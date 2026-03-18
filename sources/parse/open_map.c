/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 18:14:32 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/03/18 19:56:05 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	init_other_data(t_mlx *data)
{
	//Init other data
	(void)data;//debug
	return (1);
}

/*Files are not specifically required to be on maps/, 
 *so it is not checked*/
static int	map_format(char *file_path)
{
	char	*first_dot_position;

	if (ft_strnstr(file_path, ".cub", 4))
	{
		ft_putendl_error("Error\nGood format, but file has no name");
		return (0);
	}
	first_dot_position = ft_strchr(file_path, '.');
	if (!first_dot_position
		|| !ft_strnstr(first_dot_position, ".cub", 4)
		|| first_dot_position[4] != 0)
	{
		ft_putendl_error("Error\nExpected file format: <name>.cub");
		return (0);
	}
	return (1);
}

//Store map (And data?)

int	open_map(char *cub_file_path, t_mlx *data)
{
	if (!map_format(cub_file_path))
		return (0);
	return (init_other_data(data));
}
