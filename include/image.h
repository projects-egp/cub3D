/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:10:49 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/11 11:35:34 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <stdlib.h>
# include "mlx.h"

# define WIDTH 800
# define HEIGHT 600
# define CEILING_COLOR 0x33A1FF // Dodger Blue
# define FLOOR_COLOR 0x333333   // Dark grey
//
/*	*	KEYS	*	*/
# define ESC 65307

typedef enum e_close_program
{
	ERROR_CLOSE,
	SUCCESS_CLOSE
}	t_close_program;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	*map_data;
}				t_mlx;

void	my_pixel_put(t_img *img, int x, int y, int color);
void	draw_background(t_mlx *mlx);
uint32_t	get_color_value(int *decimal_value);
int		init_mlx_data(t_mlx *mlx, void *file_data);
void	run_mlx_loop(t_mlx *mlx);
//
/*	*	mlx events	*	*/
int		key_pressed(int key, t_mlx *mlx);
int		close_program(t_mlx *mlx, int status);

#endif
