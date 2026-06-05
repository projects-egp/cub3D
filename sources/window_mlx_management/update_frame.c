/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 13:14:48 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/05 13:47:17 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	move_step(double dir[2], t_mlx *mlx)
{
	double	move_step;

	move_step = 0.03;
	if (mlx->k_w)
	{
		dir[X_POS] += cos(mlx->map_data->player_angle) * move_step;
		dir[Y_POS] += sin(mlx->map_data->player_angle) * move_step;
	}
	if (mlx->k_s)
	{
		dir[X_POS] -= cos(mlx->map_data->player_angle) * move_step;
		dir[Y_POS] -= sin(mlx->map_data->player_angle) * move_step;
	}
	if (mlx->k_a)
	{
		dir[X_POS] += cos(mlx->map_data->player_angle - M_PI / 2) * move_step;
		dir[Y_POS] += sin(mlx->map_data->player_angle - M_PI / 2) * move_step;
	}
	if (mlx->k_d)
	{
		dir[X_POS] += cos(mlx->map_data->player_angle + M_PI / 2) * move_step;
		dir[Y_POS] += sin(mlx->map_data->player_angle + M_PI / 2) * move_step;
	}
	return ;
}

int	update_frame(t_mlx *mlx)
{
	t_map	*map;
	double	dir[POSITION];
	double	rot_step;

	map = (t_map *)mlx->map_data;
	dir[X_POS] = 0;
	dir[Y_POS] = 0;
	rot_step = 0.03;
	move_step(dir, mlx);
	if (mlx->k_l)
		map->player_angle -= rot_step;
	if (mlx->k_r)
		map->player_angle += rot_step;
	if (map->player_angle < 0)
		map->player_angle += 2 * M_PI;
	if (map->player_angle > 2 * M_PI)
		map->player_angle -= 2 * M_PI;
	if (dir[X_POS] != 0 || dir[Y_POS] != 0 || mlx->k_l || mlx->k_r)
	{
		if (map->map[(int)(map->player[Y_POS] + dir[Y_POS])][(int)(map->player[X_POS] + dir[X_POS])] != '1'
			&& map->map[(int)(map->player[Y_POS] + dir[Y_POS])][(int)(map->player[X_POS] + dir[X_POS])] != ' '
			&& map->map[(int)(map->player[Y_POS] + dir[Y_POS])][(int)(map->player[X_POS] + dir[X_POS])] != '\0')
		{
			map->player[X_POS] += dir[X_POS];
			map->player[Y_POS] += dir[Y_POS];
		}
		draw_background(mlx);
		render_3d_scene(mlx);
		draw_minimap(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				mlx->img.img_ptr, 0, 0);
	}
	return (0);
}
