/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 13:14:48 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/05 13:22:24 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	update_frame(t_mlx *mlx)
{
	t_map	*map;
	double	dx;
	double	dy;
	double	move_step;
	double	rot_step;

	map = (t_map *)mlx->map_data;
	dx = 0;
	dy = 0;
	move_step = 0.03;
	rot_step = 0.03;
	if (mlx->k_w)
	{
		dx += cos(map->player_angle) * move_step;
		dy += sin(map->player_angle) * move_step;
	}
	if (mlx->k_s)
	{
		dx -= cos(map->player_angle) * move_step;
		dy -= sin(map->player_angle) * move_step;
	}
	if (mlx->k_a)
	{
		dx += cos(map->player_angle - M_PI / 2) * move_step;
		dy += sin(map->player_angle - M_PI / 2) * move_step;
	}
	if (mlx->k_d)
	{
		dx += cos(map->player_angle + M_PI / 2) * move_step;
		dy += sin(map->player_angle + M_PI / 2) * move_step;
	}
	if (mlx->k_l)
		map->player_angle -= rot_step;
	if (mlx->k_r)
		map->player_angle += rot_step;
	if (map->player_angle < 0)
		map->player_angle += 2 * M_PI;
	if (map->player_angle > 2 * M_PI)
		map->player_angle -= 2 * M_PI;
	if (dx != 0 || dy != 0 || mlx->k_l || mlx->k_r)
	{
		if (map->map[(int)(map->player[Y_POS] + dy)][(int)(map->player[X_POS] + dx)] != '1'
			&& map->map[(int)(map->player[Y_POS] + dy)][(int)(map->player[X_POS] + dx)] != ' '
			&& map->map[(int)(map->player[Y_POS] + dy)][(int)(map->player[X_POS] + dx)] != '\0')
		{
			map->player[X_POS] += dx;
			map->player[Y_POS] += dy;
		}
		draw_background(mlx);
		render_3d_scene(mlx);
		draw_minimap(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->img.img_ptr, 0, 0);
	}
	return (0);
}
