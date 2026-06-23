/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 19:41:59 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/23 12:00:00 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	hit_wall(t_mlx *mlx, int map_x, int map_y)
{
	char	**map;
	char	c;

	if (map_y < 0 || map_y >= mlx->map_data->height
		|| map_x < 0 || map_x >= mlx->map_data->width)
		return (1);
	map = mlx->map_data->map;
	c = map[map_y][map_x];
	return (c != '0' && c != mlx->map_data->spawn_orientation);
}

double	throw_ray(t_mlx *mlx, int *side, double dx, double dy)
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;

	map_x = (int)mlx->map_data->player[X_POS];
	map_y = (int)mlx->map_data->player[Y_POS];
	delta_dist_x = (dx == 0) ? 1e30 : fabs(1.0 / dx);
	delta_dist_y = (dy == 0) ? 1e30 : fabs(1.0 / dy);
	if (dx < 0)
	{
		step_x = -1;
		side_dist_x = (mlx->map_data->player[X_POS] - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - mlx->map_data->player[X_POS]) * delta_dist_x;
	}
	if (dy < 0)
	{
		step_y = -1;
		side_dist_y = (mlx->map_data->player[Y_POS] - map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - mlx->map_data->player[Y_POS]) * delta_dist_y;
	}
	while (1)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			*side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			*side = 1;
		}
		if (hit_wall(mlx, map_x, map_y))
			break ;
	}
	if (*side == 0)
		return (side_dist_x - delta_dist_x);
	return (side_dist_y - delta_dist_y);
}
