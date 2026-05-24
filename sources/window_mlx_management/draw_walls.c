/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 18:03:31 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/24 19:41:18 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	draw_walls(t_mlx *mlx)
{
	static double	half_angle;
	static double	angle_step;
	double		ray_angle;
	double		ray_length;

	if (!half_angle)
		half_angle = mlx->map_data->fov_angle / 2;
	if (!angle_step)
		angle_step = mlx->map_data->fov_angle / WIDTH;
	ray_angle = mlx->map_data->player_angle - half_angle;
	while (ray_angle <= mlx->map_data->player_angle + half_angle)
	{
		ray_length = throw_ray(ray_angle, mlx);
		//Get ray hit point distance
		//Draw vertical stripe
		ray_angle += angle_step;
	}
	return ;
}
