/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:30:00 by mario             #+#    #+#             */
/*   Updated: 2026/04/28 19:30:05 by mario            ###   ########.fr       */
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

int	init_mlx_data(t_mlx *mlx, void *file_data)
{
	mlx->map_data = file_data;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (0);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
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