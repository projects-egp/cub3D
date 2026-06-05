/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_dda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 19:41:59 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/05 22:58:30 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	draw_vertical_line(t_mlx *mlx, int x, int wall_height, int color)
{
	int	y;
	int	start;
	int	end;

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
		return (0xFFFF00);     // Rayo sube: golpea cara SUR (Amarillo)
	}
	else // Impacto en Eje X (Paredes Este u Oeste)
	{
		if (dx > 0)
			return (0x00FF00); // Rayo va derecha: golpea cara OESTE (Verde)
		return (0x0000FF);     // Rayo va izquierda: golpea cara ESTE (Azul)
	}
}

/* STEPS
 *
 * 1) Obtain ray_angle
 * 2) With these angle, take cosine and sine
 * 3) Obtain ray distance between player and wall which has been hit
 * 4) Correct distance to avoid 'fisheye'*/
void	render_3d_scene(t_mlx *mlx)
{
	int		x;
	double	ray_angle;
	double	distance;
	int		wall_height;
	int		side;
	double	dx;
	double	dy;

	x = 0;
	while (x < WIDTH)
	{
		ray_angle = (mlx->map_data->player_angle
			- (mlx->map_data->fov_angle / 2))
			+ ((double)x / (double)WIDTH) * mlx->map_data->fov_angle;
		dx = cos(ray_angle);
		dy = sin(ray_angle);
		distance = throw_ray(mlx, &side, dx, dy);
		distance *= cos(ray_angle - mlx->map_data->player_angle);
		wall_height = (int)(HEIGHT / (distance + 0.0001));
		draw_vertical_line(mlx, x, wall_height, get_wall_color(side, dx, dy));
		++x;
	}
}
