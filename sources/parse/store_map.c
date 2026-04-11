/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 18:52:55 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/11 16:37:54 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	malloc_fail_at_store_map(t_list **map_lines)
{
	free_full_list_and_contents(map_lines);
	ft_putendl_error(MALLOC_FAILED);
	return (0);
}

/*store_map() is returned by read_data() to parse_main() as "read_status" var.
 * Here we will store and check map. In any case, we will return to parse_main()
 * and then close file descriptor from map file. Doesn't matter if we return
 * succesfully or with some error found*/
int	store_map(t_map *map_data, t_list **map_lines)
{
	int	i;

	i = map_data->height - 1;
	printf("i is %d, height is %d\n", i, map_data->height);//debug
	map_data->map = ft_calloc(map_data->height, sizeof(char *));
	if (!map_data->map)
		return (malloc_fail_at_store_map(map_lines));
	printf("list is %d\n", ft_lstsize(*map_lines));//debug
	while (i >= 0)
	{
		map_data->map[i] = ft_substr((*map_lines)->content,
				0, map_data->width);
		printf("lines %d is %s", i, map_data->map[i]);//debug
		if (!map_data->map[i])
			return (malloc_fail_at_store_map(map_lines));
		free_first_node_and_content(map_lines);
		--i;
	}
	return (1);
}
