/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:30:00 by mario             #+#    #+#             */
/*   Updated: 2026/06/05 11:57:15 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

//int	key_pressed(int keycode, t_mlx *mlx);
//int	key_released(int keycode, t_mlx *mlx);
int	update_frame(t_mlx *mlx);
void	render_3d_scene(t_mlx *mlx);

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

int	init_mlx_data(t_mlx *mlx, void *file_data)
{
	mlx->map_data = file_data;
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->img.img_ptr = NULL;
	mlx->k_w = 0;
	mlx->k_s = 0;
	mlx->k_a = 0;
	mlx->k_d = 0;
	mlx->k_l = 0;
	mlx->k_r = 0;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
	{
		print_error(INIT_MLX);
		close_program(mlx, ERROR_CLOSE);
	}
	link_images(mlx);
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
	return (1);
}

void	run_mlx_loop(t_mlx *mlx)
{
	draw_background(mlx);
	draw_minimap(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->img.img_ptr, 0, 0);
	mlx_hook(mlx->win_ptr, 2, 1L << 0, key_pressed, mlx);
	mlx_hook(mlx->win_ptr, 3, 1L << 1, key_released, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_program, mlx);
	mlx_loop_hook(mlx->mlx_ptr, update_frame, mlx);
	mlx_loop(mlx->mlx_ptr);
}

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

//"Returns" an integer as long as mlx_hook expects this behaviour
int	close_program(t_mlx *mlx, int status)
{
	clean_up(mlx);
	if (status == ERROR_CLOSE)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
	return (0);
}
