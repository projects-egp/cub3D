/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 18:14:32 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/03/18 18:27:19 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	init_other_data(t_mlx *data)
{
	//Init other data
	return (1);
}

static int	map_format(char *file_path)
{
	//Maps/ is not specifically asked
}

//Store map (And data?)

int	open_map(char *cub_file_path, t_mlx *data)
{
	if (!map_format(cub_file_path))
		return (0);
	return (init_other_data(data));
}
