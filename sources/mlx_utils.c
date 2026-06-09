/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 19:30:00 by mario             #+#    #+#             */
/*   Updated: 2026/06/09 11:51:10 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	set_data(t_mlx *mlx, void *file_data)
{
	mlx->map_data = file_data;
	mlx->mlx_ptr = NULL;
	mlx->win_ptr = NULL;
	mlx->img.img_ptr = NULL;
	ft_bzero((void *)mlx->key, (sizeof(int) * PLAYER_KEYS));
	return ;
}

/*After init mlx, first thing done is link images. 
 * In case of error, this function will call to close program, 
 * and user won't see a window trying to open on screen*/
int	init_mlx_data(t_mlx *mlx, void *file_data)
{
	set_data(mlx, file_data);
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
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	if (!mlx->img.img_ptr)
	{
		print_error(MLX_NEW_IMAGE);
		close_program(mlx, ERROR_CLOSE);
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	return (1);
}

void	run_mlx_loop(t_mlx *mlx)
{
	draw_background(mlx);
	render_3d_scene(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->img.img_ptr, 0, 0);
	mlx_hook(mlx->win_ptr, 2, 1L << 0, key_pressed, mlx);
	mlx_hook(mlx->win_ptr, 3, 1L << 1, key_released, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_program, mlx);
	mlx_loop_hook(mlx->mlx_ptr, update_frame, mlx);
	mlx_loop(mlx->mlx_ptr);
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
