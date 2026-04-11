/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 18:52:55 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/11 18:00:46 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	malloc_fail_at_store_map(t_list **map_lines)
{
	free_full_list_and_contents(map_lines);
	print_error(MALLOC_FAILED);
	return (0);
}

/*store_map() is returned by read_data() to parse_main() as "read_status" var.
 * Here we will store and check map. In any case, we will return to parse_main()
 * and then close file descriptor from map file. Doesn't matter if we return
 * succesfully or with some error found*/
int	store_map(t_map *map_data, t_list **map_lines)
{
	int	i;

	if (!map_data->spawn_orientation)
		return (malloc_fail_at_store_map(map_lines));
	i = map_data->height - 1;
	map_data->map = ft_calloc(map_data->height + 1, sizeof(char *));
	if (!map_data->map)
		return (malloc_fail_at_store_map(map_lines));
	while (i >= 0)
	{
		map_data->map[i] = ft_substr((*map_lines)->content,
				0, map_data->width);
		if (!map_data->map[i])
			return (malloc_fail_at_store_map(map_lines));
		free_first_node_and_content(map_lines);
		--i;
	}
	return (1);
}
