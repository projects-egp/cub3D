/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:30:00 by mario             #+#    #+#             */
/*   Updated: 2026/06/08 16:58:08 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	draw_square(t_img *img, t_minimap data, int color)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	size;

	x = data.x * data.t_s + data.offset;
	y = data.y * data.t_s + data.offset;
	size = data.t_s;
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

static void	call_draw_square(t_mlx *mlx, t_minimap data, t_map *map)
{
	int	x;
	int	y;

	x = data.x;
	y = data.y;
	if (map->map[y][x] == '1')
		draw_square(&mlx->img, data, BLACK);
	else if (map->map[y][x] != ' ' && map->map[y][x] != '\n')
		draw_square(&mlx->img, data, WHITE);
}

static void	draw_fov(t_img *img, t_map *map, t_minimap data, int color)
{
	int		i;
	int		x;
	int		y;
	double	angle;
	int		size;

	x = (int)(map->player[X_POS] * data.t_s) + data.offset;
	y = (int)(map->player[Y_POS] * data.t_s) + data.offset;
	angle = map->player_angle;
	size = data.t_s * 1.25;
	i = 0;
	while (i < size * 2)
	{
		my_pixel_put(img, x + cos(angle) * i, y + sin(angle) * i, color);
		i++;
	}
}

void	draw_minimap(t_mlx *mlx)
{
	t_map		*map;
	t_minimap	minimap;

	map = (t_map *)mlx->map_data;
	minimap.t_s = (HEIGHT / 5) / map->height;
	if (map->width > 0 && (WIDTH / 5) / map->width < minimap.t_s)
		minimap.t_s = (WIDTH / 5) / map->width;
	if (minimap.t_s < 1)
		minimap.t_s = 1;
	minimap.offset = 20;
	minimap.y = -1;
	while (++minimap.y < map->height)
	{
		minimap.x = -1;
		while (++minimap.x < map->width && map->map[minimap.y][minimap.x])
			call_draw_square(mlx, minimap, map);
	}
	draw_fov(&mlx->img, map, minimap, 0xFF0000);
}
