/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:10:49 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/23 12:37:25 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# define WIDTH 800
# define HEIGHT 600

typedef enum e_close_program
{
	ERROR_CLOSE,
	SUCCESS_CLOSE
}	t_close_program;

typedef enum e_pressed_keys
{
	W_KEY = 0,
	S_KEY,
	A_KEY,
	D_KEY,
	LEFT_KEY,
	RIGHT_KEY,
	PLAYER_KEYS
}	t_pressed_keys;

typedef struct s_dda
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
}	t_dda;

typedef struct s_minimap
{
	int	t_s;
	int	x;
	int	y;
	int	offset;
}	t_minimap;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	textures[TEXTURE_PATHS];
	t_img	img;
	t_map	*map_data;
	int		key[PLAYER_KEYS];
}				t_mlx;

void	my_pixel_put(t_img *img, int x, int y, int color);
void	draw_background(t_mlx *mlx);
double	throw_ray(t_mlx *mlx, int *side, double dx, double dy);
int		init_mlx_data(t_mlx *mlx, void *file_data);
void	link_images(t_mlx *mlx);
void	run_mlx_loop(t_mlx *mlx);
//
/*	*	update_frame	*	*/
int		update_frame(t_mlx *mlx);
void	render_3d_scene(t_mlx *mlx);
//
/*	*	mlx events	*	*/
int		key_pressed(int key, t_mlx *mlx);
int		key_released(int key, t_mlx *mlx);
int		close_program(t_mlx *mlx, int status);

#endif
