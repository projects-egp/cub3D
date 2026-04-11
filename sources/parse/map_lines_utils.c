/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lines_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:29:37 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/11 17:59:47 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

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

static int	player_found(int cardinal_direction_view, int x_position,
		t_map *map_data)
{
	map_data->spawn_orientation = cardinal_direction_view;
	map_data->player[X_POS] = x_position;
	map_data->player[Y_POS] = map_data->height;
	return (1);
}

/*For map content, only space that will be acceptable will be ascii 32, ' '.
 * This decision has been taken because other whitespaces 
 * like tabs can break our map*/
int	is_valid_map_char(int c, int x_position, t_map *map_data)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
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
	print_error(WRONG_CHAR_FOUND);
	return (0);
}
