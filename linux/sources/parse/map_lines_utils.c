/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lines_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:29:37 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/25 13:14:43 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	is_spawn_char(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (1);
	return (0);
}

/*Used on add_valid_map_line. In cases of first or last char,
 * is needed to check here if first or last char of a read line is a valid
 * char but will make a not surrounded map. SO, checks only spawn char
 * or 0*/
int	check_first_and_last_chars(char *line, int len)
{
	char	first;
	char	last;

	first = line[0];
	last = line[len - 2];
	if (is_spawn_char(first) || first == '0'
		|| is_spawn_char(last) || last == '0')
	{
		print_error(MAP_NOT_CLOSED);
		return (0);
	}
	return (1);
}

int	add_new_line_to_list(char *line, t_list **map_lines_list)
{
	t_list	*new;

	new = NULL;
	new = ft_lstnew(line);
	if (!new)
	{
		free_full_list_and_contents(map_lines_list);
		return (0);
	}
	ft_lstadd_front(map_lines_list, new);
	return (1);
}

	/*Radians for orthogonal angles are set in order to be consistent with
	 * a map that increase x value from west to east and increase y value 
	 * from north to south. For example, an angle pointing to northeast
	 * would have a direction vector with cos(angle) = positive x and
	 * sin(angle) = negative y*/
static int	player_found(int cardinal_direction_view, int x_position,
		t_map *map_data)
{
	if (cardinal_direction_view == 'E')
		map_data->player_angle = 0;
	else if (cardinal_direction_view == 'S')
		map_data->player_angle = M_PI / 2;
	else if (cardinal_direction_view == 'W')
		map_data->player_angle = M_PI;
	if (cardinal_direction_view == 'N')
		map_data->player_angle = 3 * M_PI / 2;
	map_data->fov_angle = (FOV_ANGLE * M_PI) / 180;
	map_data->spawn_orientation = cardinal_direction_view;
	map_data->player[X_POS] = (double)x_position + 0.5;
	map_data->player[Y_POS] = (double)map_data->height + 0.5;
	return (1);
}

/*For map content, only space that will be acceptable will be ascii 32, ' '.
 * This decision has been taken because other whitespaces 
 * like tabs can break our map*/
int	is_valid_map_char(int c, int x_position, t_map *map_data)
{
	if (is_spawn_char(c))
	{
		if (map_data->spawn_orientation != 0)
		{
			print_error(TWO_PLAYER_POSITIONS);
			return (0);
		}
		return (player_found(c, x_position, map_data));
	}
	if (c == '1' || c == '0' || c == ' ' || c == '\n')
		return (1);
	if (ft_isspace(c))
		print_error(WHITESPACE_ON_MAP);
	else
		print_error(WRONG_CHAR_FOUND);
	return (0);
}
