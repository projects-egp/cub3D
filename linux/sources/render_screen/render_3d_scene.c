/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 19:41:59 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/26 22:04:36 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static double	hit_position(t_mlx *mlx, double distance,
		double dir[2], int side)
{
	double	wall_x;

	wall_x = 0;
	if (side == Y_POS)
		wall_x = mlx->map_data->player[X_POS] + distance * dir[X_POS];
	else
		wall_x = mlx->map_data->player[Y_POS] + distance * dir[Y_POS];
	wall_x -= floor(wall_x);
	return (wall_x);
}

/* STEPS
 *
 * 1) Obtain ray_angle
 * 2) With these angle, take cosine and sine
 * 3) Obtain ray distance between player and wall which has been hit
 * 4) Correct distance to avoid 'fisheye'
 * 5) Draw a vertical stripe*/
void	render_3d_scene(t_mlx *mlx)
{
	t_wall			wall;
	int				x;
	double			ray_angle;

	x = 0;
	while (x < WIDTH)
	{
		ray_angle = (mlx->map_data->player_angle
				- (mlx->map_data->fov_angle / 2))
			+ ((double)x / (double)WIDTH) * mlx->map_data->fov_angle;
		wall.dir[X_POS] = cos(ray_angle);
		wall.dir[Y_POS] = sin(ray_angle);
		wall.distance = throw_ray(mlx, &wall.side,
				wall.dir[X_POS], wall.dir[Y_POS]);
		wall.hit_position = hit_position(mlx, wall.distance,
				wall.dir, wall.side);
		wall.distance *= cos(ray_angle - mlx->map_data->player_angle);
		draw_vertical_line(mlx, x, &wall);
		++x;
	}
}
