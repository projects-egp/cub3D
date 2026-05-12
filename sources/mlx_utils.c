/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:30:00 by mario             #+#    #+#             */
/*   Updated: 2026/05/12 10:45:33 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	key_pressed(int keycode, t_mlx *mlx);

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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

static void	draw_fov(t_img *img, int x, int y, char dir, int size, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -i - 1;
		while (++j <= i)
		{
			if (dir == 'N')
				my_pixel_put(img, x + j, y - i, color);
			else if (dir == 'S')
				my_pixel_put(img, x + j, y + i, color);
			else if (dir == 'E')
				my_pixel_put(img, x + i, y + j, color);
			else if (dir == 'W')
				my_pixel_put(img, x - i, y + j, color);
		}
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
		map->player[X_POS] * t_s + offset + (t_s / 2),
		map->player[Y_POS] * t_s + offset + (t_s / 2),
		map->spawn_orientation, t_s * 2, 0xFFFF00);
}

int	init_mlx_data(t_mlx *mlx, void *file_data)
{
	mlx->map_data = file_data;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
	{
		print_error(INIT_MLX);
		close_program(mlx, ERROR_CLOSE);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	if (!mlx->win_ptr)
	{
		print_error(WINDOW_MLX);
		close_program(mlx, ERROR_CLOSE);
	}
	/*If mlx->img.img_ptr is not NULL,
	 * should destroy first and later new_image again*/
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	if (!mlx->img.img_ptr)
	{
		print_error(MLX_NEW_IMAGE);
		close_program(mlx, ERROR_CLOSE);
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	link_images(mlx);
	return (1);
}

void	run_mlx_loop(t_mlx *mlx)
{
	draw_background(mlx);
	draw_minimap(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->img.img_ptr, 0, 0);
	mlx_hook(mlx->win_ptr, 2, 1L << 0, key_pressed, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_program, mlx);
	mlx_loop(mlx->mlx_ptr);
}

int	key_pressed(int key, t_mlx *mlx)
{
	t_map	*map;
	int		dx;
	int		dy;

	map = (t_map *)mlx->map_data;
	dx = 0;
	dy = 0;
	if (key == 53 || key == 65307)
		close_program(mlx, 0);
	if (key == 13 || key == 119)
		{dy = -1; map->spawn_orientation = 'N';}
	else if (key == 1 || key == 115)
		{dy = 1; map->spawn_orientation = 'S';}
	else if (key == 0 || key == 97)
		{dx = -1; map->spawn_orientation = 'W';}
	else if (key == 2 || key == 100)
		{dx = 1; map->spawn_orientation = 'E';}
	if (dx != 0 || dy != 0)
	{
		if (map->player[Y_POS] + dy >= 0 && map->player[Y_POS] + dy < map->height
			&& map->player[X_POS] + dx >= 0 && map->player[X_POS] + dx < map->width
			&& map->map[map->player[Y_POS] + dy][map->player[X_POS] + dx] != '1'
			&& map->map[map->player[Y_POS] + dy][map->player[X_POS] + dx] != ' ')
		{
			map->player[X_POS] += dx;
			map->player[Y_POS] += dy;
		}
		draw_background(mlx);
		draw_minimap(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->img.img_ptr, 0, 0);
	}
	return (0);
}

//"Returns" an integer as long as mlx_hook expects this behaviour
int	close_program(t_mlx *mlx, int status)
{
	clean_up(mlx);
	if (status == ERROR_CLOSE)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
	return (0);
}
