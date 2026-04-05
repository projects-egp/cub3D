/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lines_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:29:37 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/05 16:53:16 by enrgil-p         ###   ########.fr       */
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

static void	player_found(int cardinal_direction_view, int x_position,
			t_map *map_data);
{
	map_data->player_view = cardinal_direction_view;
	map_data->player[X_POS] = x_position;
	map_data->player[Y_POS] = map_data->height + 1;
	return ;
}

int	is_valid_map_char(int c, int x_position, t_map *map_data)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
	{
		if (map_data->player_view != 0)
		{
			//error message: map must have just one start position
			return (0);
		}
		player_found(c, x_pos, file_data);
	}
	return (1);
}
