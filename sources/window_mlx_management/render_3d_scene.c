/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 19:41:59 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/07 14:54:00 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	draw_vertical_line(t_mlx *mlx, int x, double distance, int color)
{
	int	wall_height;
	int	y;
	int	start;
	int	end;

	wall_height = (int)(HEIGHT / (distance + 0.0001));
	start = (HEIGHT / 2) - (wall_height / 2);
	end = (HEIGHT / 2) + (wall_height / 2);
	if (start < 0)
		start = 0;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	y = start;
	while (y < end)
	{
		my_pixel_put(&mlx->img, x, y, color);
		y++;
	}
}

static int	get_wall_color(int side, double dx, double dy)
{
	if (side == 1) // Impacto en Eje Y (Paredes Norte o Sur)
	{
		if (dy > 0)
			return (0xFF0000); // Rayo baja: golpea cara NORTE (Rojo)
		return (0xFFFF00);// Rayo sube: golpea cara SUR (Amarillo)
	}
	else // Impacto en Eje X (Paredes Este u Oeste)
	{
		if (dx > 0)
			return (0x00FF00); // Rayo va derecha: golpea cara OESTE (Verde)
		return (0x0000FF);// Rayo va izquierda: golpea cara ESTE (Azul)
	}
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
	int		x;
	double	ray_angle;
	double	distance;
	int		side;
	double	dir[POSITION];

	x = 0;
	while (x < WIDTH)
	{
		ray_angle = (mlx->map_data->player_angle
				- (mlx->map_data->fov_angle / 2))
			+ ((double)x / (double)WIDTH) * mlx->map_data->fov_angle;
		dir[X_POS] = cos(ray_angle);
		dir[Y_POS] = sin(ray_angle);
		distance = throw_ray(mlx, &side, dir[X_POS], dir[Y_POS]);
		distance *= cos(ray_angle - mlx->map_data->player_angle);
		draw_vertical_line(mlx, x, distance,
			get_wall_color(side, dir[X_POS], dir[Y_POS]));
		++x;
	}
}
