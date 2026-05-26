/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 18:03:31 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/26 18:59:11 by enrgil-p         ###   ########.fr       */
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
		//Draw vertical stripe
		/*To start, first just print one color.
		 * We will later print wall textures*/
		/*To print textures, we will need ray_angle,
		 * to now if hit point was part of NORTH EAST wall 
		 * or SOUTH WEST, for example*/
		ray_angle += angle_step;
	}
	return ;
}
