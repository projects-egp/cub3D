/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_dda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 19:41:59 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/25 18:02:52 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static double	get_step(double position, double ray_direction_value, 
		int increase)
{
	double	step;
	doble	side;

	if (ray_direction_value < 0)
		increase *= -1;
	side = increase - position; 
	step = side / ray_direction_value;
	return (step);
}

static double	find_next_square(t_ray *ray)
{
	double	step_x;
	double	step_y;
	double	result;

	result = 0;
	step_x = get_step(ray->position[X_POS], ray->direction[X_POS],
			ray->increase[X_POS]);
	step_y = get_step();
	if (step_x > step_y)
	{
		result = step_x;
		ray->increase_x += 1;
	}
}

double	throw_ray(double angle, t_mlx *mlx)
{
	double	length;
	t_ray	ray_data;

	length = 0;
	ray_data.direction[X_POS] = cos(angle);
	ray_data.direction[Y_POS] = sin(angle);
	ray_data.position[X_POS] = mlx->map_data->player[X_POS];
	ray_data.position[Y_POS] = mlx->map_data->player[Y_POS];
	ray_data.increase[X_POS] = 0;
	ray_data.increase[Y_POS] = 0;
	while ()
	{
		//Find next square
		length += find_next_square(&ray_data);
	}
	return (length);
}
