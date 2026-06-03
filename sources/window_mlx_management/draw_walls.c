/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 18:03:31 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/03 12:14:11 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	draw_walls(t_mlx *mlx)
{
	static double	half_angle;
	static double	angle_step;
	double		ray_angle;
	int			side;
	double		dx;
	double		dy;

	if (!half_angle)
		half_angle = mlx->map_data->fov_angle / 2;
	if (!angle_step)
		angle_step = mlx->map_data->fov_angle / WIDTH;
	ray_angle = mlx->map_data->player_angle - half_angle;
	while (ray_angle <= mlx->map_data->player_angle + half_angle)
	{
		throw_ray(ray_angle, mlx, &side, &dx, &dy);
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
