/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_dda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 19:41:59 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/24 20:39:59 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	set_ray_vector(double *ray_vector[2], t_map *map)
{
	*ray_vector[X_POS] = map->player_position[X_POS];
	*ray_vector[Y_POS] = map->player_position[Y_POS];

	return ;
}

static double	find_next_square()
{
	//I need to now if x|y++ or x|y--
}

double	throw_ray(double angle, t_mlx *mlx)
{
	double	length;
	double	ray_vector[POSITION];

	length = 0;
	set_ray_vector(&ray_vector, mlx->map_data);
	while ()
	{
		//Find next square
		length += find_next_square();
	}
	return (length);
}
