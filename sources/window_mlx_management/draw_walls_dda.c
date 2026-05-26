/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_dda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 19:41:59 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/26 17:50:24 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "general.h"
#include "../../include/testing.h"

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

	step_x = get_step(ray->position[X_POS], ray->direction[X_POS]);
	step_y = get_step(ray->position[Y_POS], ray->direction[Y_POS]);
	if (step_x > step_y)
	{
		ray->position[X_POS] += ray->direction[X_POS] * step_y;
		ray->position[Y_POS] += get_side(ray->position[Y_POS],
				ray->direction[Y_POS]);
		result = step_y;
	}
	else
	{
		ray->position[Y_POS] += ray->direction[Y_POS] * step_x;
		ray->position[X_POS] += get_side(ray->position[X_POS],
				ray->direction[X_POS]);
		result = step_x;
	}
	return (result);
}

double	throw_ray(double angle/*, t_mlx *mlx*/)
{
	double	length;
	t_ray	ray_data;

	length = 0;
	ray_data.direction[X_POS] = cos(angle);
	ray_data.direction[Y_POS] = sin(angle);
	ray_data.position[X_POS] = 4.0;//mlx->map_data->player[X_POS];
	ray_data.position[Y_POS] = 4.000;//mlx->map_data->player[Y_POS];
	/*while (!ray_hit_wall(ray_data))
	{
		//Find next square
	*/	length += find_next_square(&ray_data);
		printf("Side x == %f\n", ray_data.position[X_POS]);
		printf("Side y == %f\n", ray_data.position[Y_POS]);
	//}
	return (length);
}

int	main(void)
{
	double	angle;
	double	result;

	angle = (30 * M_PI) / 180;
	result = throw_ray(angle);
	printf("Result is %f\n", result);
	return (0);
}
