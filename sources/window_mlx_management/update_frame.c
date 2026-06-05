/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 13:14:48 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/05 20:45:06 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	check_keys_to_move(double dir[2], t_mlx *mlx)
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

/*Also updates angle to keep values between 0 - (2 * PI)*/
static void	check_keys_to_rotate(t_mlx *mlx)
{
	double	rot_step;

	rot_step = 0.03;
	if (mlx->k_l)
		mlx->map_data->player_angle -= rot_step;
	if (mlx->k_r)
		mlx->map_data->player_angle += rot_step;
	if (mlx->map_data->player_angle < 0)
		mlx->map_data->player_angle += 2 * M_PI;
	if (mlx->map_data->player_angle > 2 * M_PI)
		mlx->map_data->player_angle -= 2 * M_PI;
	return ;
}

static char	next_position(t_map *map, double dir[2])
{
	char	next_position;
	double	y_coord;
	double	x_coord;

	y_coord = map->player[Y_POS] + dir[Y_POS];
	x_coord = map->player[X_POS] + dir[X_POS];
	next_position = map->map[(int)y_coord][(int)x_coord];
	return (next_position);
}

static void	move_player(t_mlx *mlx, double dir[2])
{
	t_map	*map;

	map = (t_map *)mlx->map_data;
	if (next_position(map, dir) != '1' && next_position(map, dir) != ' '
		&& next_position(map, dir) != '\0')
	{
		map->player[X_POS] += dir[X_POS];
		map->player[Y_POS] += dir[Y_POS];
	}
	return ;
}

int	update_frame(t_mlx *mlx)
{
	double	dir[POSITION];

	dir[X_POS] = 0;
	dir[Y_POS] = 0;
	check_keys_to_move(dir, mlx);
	check_keys_to_rotate(mlx);
	if (dir[X_POS] != 0 || dir[Y_POS] != 0 || mlx->k_l || mlx->k_r)
	{
		move_player(mlx, dir);
		draw_background(mlx);
		render_3d_scene(mlx);
		draw_minimap(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->img.img_ptr, 0, 0);
	}
	return (0);
}
