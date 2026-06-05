/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:30:00 by mario             #+#    #+#             */
/*   Updated: 2026/06/05 21:04:25 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	draw_square(t_img *img, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_pixel_put(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

static void	draw_fov(t_img *img, int x, int y, double angle, int size, int color)
{
	int	i;

	i = 0;
	while (i < size * 2)
	{
		my_pixel_put(img, x + cos(angle) * i, y + sin(angle) * i, color);
		i++;
	}
}

void	draw_minimap(t_mlx *mlx)
{
	t_map	*map;
	int		t_s;
	int		x;
	int		y;
	int		offset;

	map = (t_map *)mlx->map_data;
	t_s = (HEIGHT / 5) / map->height;
	if (map->width > 0 && (WIDTH / 5) / map->width < t_s)
		t_s = (WIDTH / 5) / map->width;
	if (t_s < 1)
		t_s = 1;
	offset = 20;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width && map->map[y][x])
		{
			if (map->map[y][x] == '1')
				draw_square(&mlx->img, x * t_s + offset, y * t_s + offset, t_s, 0x000000);
			else if (map->map[y][x] != ' ' && map->map[y][x] != '\n')
				draw_square(&mlx->img, x * t_s + offset, y * t_s + offset, t_s, 0xFFFFFF);
		}
	}
	draw_fov(&mlx->img,
		(int)(map->player[X_POS] * t_s) + offset,
		(int)(map->player[Y_POS] * t_s) + offset,
		map->player_angle, t_s * 2, 0xFF0000);
}
