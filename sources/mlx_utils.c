/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:30:00 by mario             #+#    #+#             */
/*   Updated: 2026/05/08 11:26:53 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_background(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				my_pixel_put(&mlx->img, x, y, CEILING_COLOR);
			else
				my_pixel_put(&mlx->img, x, y, FLOOR_COLOR);
			x++;
		}
		y++;
	}
}

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
	draw_square(&mlx->img, map->player[X_POS] * t_s + offset,
		map->player[Y_POS] * t_s + offset, t_s, 0xFFFF00);
}

int	init_mlx_data(t_mlx *mlx, void *file_data)
{
	mlx->map_data = file_data;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (0);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	if (!mlx->win_ptr)
		return (0);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	if (!mlx->img.img_ptr)
		return (0);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	return (1);
}

void	run_mlx_loop(t_mlx *mlx)
{
	draw_background(mlx);
	draw_minimap(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->img.img_ptr, 0, 0);
	mlx_hook(mlx->win_ptr, 17, 0, close_program, mlx);
	mlx_loop(mlx->mlx_ptr);
}

int	close_program(t_mlx *mlx)
{
	clean_up(mlx);
	exit(0);
	return (0);
}
