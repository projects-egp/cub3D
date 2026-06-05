/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 19:41:59 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/05 22:35:56 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

/*ray_direction_value is a sine or cosine. If it is negative, 
 * x or y values of ray will decrease*/
static double	get_side(double position, double ray_direction_value)
{
	double	side;

	side = 0;
	if (ray_direction_value < 0)
	{
		side = position - floor(position);
		if (side < 0.000000001)
			return (1.0);
	}
	else
	{
		side = (floor(position) + 1.0) - position;
		if (side < 0.000000001)
			return (1.0);
	}
	return (side);
}

/*ray_direction_value is a sine or cosine. With same formula
 * we can get hypotenuse h. 
 *
 * h = side / (sin || cos)
 *
 * If (sin || cos) == 0, side / ray_direction_value is 
 * protected to avoid a zero-valued divisor*/
static double	get_step(double position, double ray_direction_value)
{
	double	step_hypotenuse;
	double	side;

	if (ray_direction_value == 0)
		return (1e30);
	side = get_side(position, ray_direction_value);
	step_hypotenuse = side / ray_direction_value;
	if (step_hypotenuse < 0)
		step_hypotenuse *= -1;
	return (step_hypotenuse);
}

/*Here is found which axis is nearest from current ray->head.
 * Nearest one will be chosen as next step, modifying head position
 * and also setting side on NORTH/SOUTH or EAST/WEST axis*/
static double	find_next_square(t_ray *ray, int *side)
{
	double	step_x;
	double	step_y;
	double	result;

	step_x = get_step(ray->head[X_POS], ray->direction[X_POS]);
	step_y = get_step(ray->head[Y_POS], ray->direction[Y_POS]);
	if (step_x > step_y)
	{
		ray->head[X_POS] += ray->direction[X_POS] * step_y;
		ray->head[Y_POS] += ray->direction[Y_POS] * step_y;
		*side = 1;//USE SOME MACRO TO MAKE EASIER TO UNDERSTAND
		result = step_y;
	}
	else
	{
		ray->head[Y_POS] += ray->direction[Y_POS] * step_x;
		ray->head[X_POS] += ray->direction[X_POS] * step_x;
		*side = 0;
		result = step_x;
	}
	return (result);
}

static int	ray_hit_wall(t_ray ray, t_mlx *mlx)
{
	char	**map;
	int		x;
	int		y;

	map = mlx->map_data->map;
	// Usamos un pequeño margen (épsilon) para mirar "dentro" del muro
	x = (int)floor(ray.head[X_POS] + (ray.direction[X_POS] * 0.00001));
	y = (int)floor(ray.head[Y_POS] + (ray.direction[Y_POS] * 0.00001));
	if (y >= 0 && y < mlx->map_data->height && x >= 0
		&& x < mlx->map_data->width)
	{
		if (map[y][x] == '0' || map[y][x] == mlx->map_data->spawn_orientation)
			return (0);
	}
	return (1);
}

/*ray is thrown on a loop. Two ways to stop loop: 
 * 	- some wall is found;
 * 	- ray is so long and haven't reached a wall yet;
 *Last way is a protection to avoid infinite loops*/
double	throw_ray(t_mlx *mlx, int *side, double dx, double dy)
{
	double	length;
	t_ray	ray_data;

	length = 0;
	*side = 0;
	ray_data.direction[X_POS] = dx;
	ray_data.direction[Y_POS] = dy;
	ray_data.head[X_POS] = mlx->map_data->player[X_POS];
	ray_data.head[Y_POS] = mlx->map_data->player[Y_POS];
	while (length < 100)
	{
		length += find_next_square(&ray_data, side);
		if (ray_hit_wall(ray_data, mlx))
			break ;
	}
	return (length);
}
