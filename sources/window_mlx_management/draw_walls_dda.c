/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_dda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 19:41:59 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/26 19:25:10 by enrgil-p         ###   ########.fr       */
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
		side = position - floor(position); 
	else
		side = (floor(position) + 1) - position; 
	return (side);
}

/*ray_direction_value is a sine or cosine. With same formula
 * we can get hypotenuse h. 
 * h = side / (sin || cos)*/
static double	get_step(double position, double ray_direction_value)
{
	double	step_hypotenuse;
	double	side;

	side = get_side(position, ray_direction_value);	
	step_hypotenuse = side / ray_direction_value;
	if (step_hypotenuse < 0)
		step_hypotenuse *= -1;
	return (step_hypotenuse);
}

static double	find_next_square(t_ray *ray)
{
	double	step_x;
	double	step_y;
	double	result;

	step_x = get_step(ray->head[X_POS], ray->direction[X_POS]);
	step_y = get_step(ray->head[Y_POS], ray->direction[Y_POS]);
	if (step_x > step_y)
	{
		ray->head[X_POS] += ray->direction[X_POS] * step_y;
		ray->head[Y_POS] += get_side(ray->head[Y_POS],
				ray->direction[Y_POS]);
		result = step_y;
	}
	else
	{
		ray->head[Y_POS] += ray->direction[Y_POS] * step_x;
		ray->head[X_POS] += get_side(ray->head[X_POS],
				ray->direction[X_POS]);
		result = step_x;
	}
	return (result);
}

static int	ray_hit_wall(t_ray ray, t_mlx *mlx)
{
	char	**map;
	int	x;
	int	y;
	
	map = mlx->map_data->map;
	x = floor(ray.head[X_POS]);
	y = floor(ray.head[Y_POS]);
	if (map[y][x] == '0')
		return (0);
	return (1);
}

double	throw_ray(double angle, t_mlx *mlx)
{
	double	length;
	t_ray	ray_data;

	length = 0;
	ray_data.direction[X_POS] = cos(angle);
	ray_data.direction[Y_POS] = sin(angle);
	ray_data.head[X_POS] = mlx->map_data->player[X_POS];
	ray_data.head[Y_POS] = mlx->map_data->player[Y_POS];
	while (1)
	{
		length += find_next_square(&ray_data);
		if (ray_hit_wall(ray_data, mlx))
			break ;
	}
	return (length);
}
