/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 13:14:48 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/10 11:04:53 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	check_keys_to_move(double dir[2], t_mlx *mlx)
{
	double	move_step;

	move_step = 0.03;
	if (mlx->key[W_KEY])
	{
		dir[X_POS] += cos(mlx->map_data->player_angle) * move_step;
		dir[Y_POS] += sin(mlx->map_data->player_angle) * move_step;
	}
	if (mlx->key[S_KEY])
	{
		dir[X_POS] -= cos(mlx->map_data->player_angle) * move_step;
		dir[Y_POS] -= sin(mlx->map_data->player_angle) * move_step;
	}
	if (mlx->key[A_KEY])
	{
		dir[X_POS] += cos(mlx->map_data->player_angle - M_PI / 2) * move_step;
		dir[Y_POS] += sin(mlx->map_data->player_angle - M_PI / 2) * move_step;
	}
	if (mlx->key[D_KEY])
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
	if (mlx->key[LEFT_KEY])
		mlx->map_data->player_angle -= rot_step;
	if (mlx->key[RIGHT_KEY])
		mlx->map_data->player_angle += rot_step;
	if (mlx->map_data->player_angle < 0)
		mlx->map_data->player_angle += 2 * M_PI;
	if (mlx->map_data->player_angle > 2 * M_PI)
		mlx->map_data->player_angle -= 2 * M_PI;
	return ;
}

static void	move_player(t_mlx *mlx, double dir[2])
{
	t_map	*map;
	double	margin;

	map = (t_map *)mlx->map_data;
	margin = 0.2;
	if (dir[X_POS] < 0)
		margin = -0.2;
	if (map->map[(int)map->player[Y_POS]]
		[(int)(map->player[X_POS] + dir[X_POS] + margin)] != '1'
		&& map->map[(int)map->player[Y_POS]]
		[(int)(map->player[X_POS] + dir[X_POS] + margin)] != ' '
		&& map->map[(int)map->player[Y_POS]]
		[(int)(map->player[X_POS] + dir[X_POS] + margin)] != '\0')
		map->player[X_POS] += dir[X_POS];
	margin = 0.2;
	if (dir[Y_POS] < 0)
		margin = -0.2;
	if (map->map[(int)(map->player[Y_POS] + dir[Y_POS] + margin)]
		[(int)map->player[X_POS]] != '1'
		&& map->map[(int)(map->player[Y_POS] + dir[Y_POS] + margin)]
		[(int)map->player[X_POS]] != ' '
		&& map->map[(int)(map->player[Y_POS] + dir[Y_POS] + margin)]
		[(int)map->player[X_POS]] != '\0')
		map->player[Y_POS] += dir[Y_POS];
}

int	update_frame(t_mlx *mlx)
{
	double	dir[POSITION];

	dir[X_POS] = 0;
	dir[Y_POS] = 0;
	check_keys_to_move(dir, mlx);
	check_keys_to_rotate(mlx);
	if (dir[X_POS] != 0 || dir[Y_POS] != 0
		|| mlx->key[LEFT_KEY] || mlx->key[RIGHT_KEY])
	{
		move_player(mlx, dir);
		draw_background(mlx);
		render_3d_scene(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->img.img_ptr, 0, 0);
	}
	return (0);
}
