/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 18:52:55 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/13 18:50:06 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	error_found(t_list **map_lines, char *message)
{
	free_full_list_and_contents(map_lines);
	print_error(message);
	return (0);
}

/*store_map() is returned by read_data() to parse_main() as "read_status" var.
 * Here we will store and check map. In any case, we will return to parse_main()
 * and then close file descriptor from map file. Doesn't matter if we return
 * succesfully or with some error found*/
int	store_map(t_map *map_data, t_list **map_lines)
{
	int	i;

	if (map_data->parse_checklist <= 6)
		return (error_found(map_lines, UNCOMPLETE_DATA));
	if (!map_data->spawn_orientation)
		return (error_found(map_lines, MAP_WITHOUT_SPAWN));
	i = map_data->height - 1;
	map_data->map = ft_calloc(map_data->height + 1, sizeof(char *));
	if (!map_data->map)
		return (error_found(map_lines, MALLOC_FAILED));
	while (i >= 0)
	{
		map_data->map[i] = ft_substr((*map_lines)->content,
				0, map_data->width);
		if (!map_data->map[i])
			return (error_found(map_lines, MALLOC_FAILED));
		free_first_node_and_content(map_lines);
		--i;
	}
	return (1);
}
