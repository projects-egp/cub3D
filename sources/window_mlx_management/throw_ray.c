/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 19:41:59 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/24 10:00:00 by mario            ###   ########.fr       */
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

static void	init_step_x(t_dda *d, double px, double dx)
{
	if (dx == 0)
		d->delta_dist_x = 1e30;
	else
		d->delta_dist_x = fabs(1.0 / dx);
	if (dx < 0)
	{
		d->step_x = -1;
		d->side_dist_x = (px - d->map_x) * d->delta_dist_x;
	}
	else
	{
		d->step_x = 1;
		d->side_dist_x = (d->map_x + 1.0 - px) * d->delta_dist_x;
	}
}

static void	init_step_y(t_dda *d, double py, double dy)
{
	if (dy == 0)
		d->delta_dist_y = 1e30;
	else
		d->delta_dist_y = fabs(1.0 / dy);
	if (dy < 0)
	{
		d->step_y = -1;
		d->side_dist_y = (py - d->map_y) * d->delta_dist_y;
	}
	else
	{
		d->step_y = 1;
		d->side_dist_y = (d->map_y + 1.0 - py) * d->delta_dist_y;
	}
}

static void	init_dda(t_dda *d, t_mlx *mlx, double dx, double dy)
{
	double	px;
	double	py;

	px = mlx->map_data->player[X_POS];
	py = mlx->map_data->player[Y_POS];
	d->map_x = (int)px;
	d->map_y = (int)py;
	init_step_x(d, px, dx);
	init_step_y(d, py, dy);
}

double	throw_ray(t_mlx *mlx, int *side, double dx, double dy)
{
	t_dda	d;

	init_dda(&d, mlx, dx, dy);
	while (1)
	{
		if (d.side_dist_x < d.side_dist_y)
		{
			d.side_dist_x += d.delta_dist_x;
			d.map_x += d.step_x;
			*side = 0;
		}
		else
		{
			d.side_dist_y += d.delta_dist_y;
			d.map_y += d.step_y;
			*side = 1;
		}
		if (hit_wall(mlx, d.map_x, d.map_y))
			break ;
	}
	if (*side == 0)
		return (d.side_dist_x - d.delta_dist_x);
	return (d.side_dist_y - d.delta_dist_y);
}
