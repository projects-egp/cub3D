/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 19:41:59 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/26 21:02:42 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static double	get_texture_x(double wall_x, t_img texture,
		t_vertical_line *wall)
{
	double	texture_x;

	texture_x = wall_x * texture.width;
	if ((wall->side == 1 && wall->dir[Y_POS] > 0)
		|| (wall->side == 0 && wall->dir[X_POS] < 0))
		texture_x = texture.width - texture_x - 1;
	return (texture_x);
}

//side is the axis where hit position has happened 
//dx and dy gives info from ray direction, to specify wall side hit, so we
//can choose it's texture
static t_img	get_texture(t_mlx *mlx, int side, double dx, double dy)
{
	if (side == Y_POS)
	{
		if (dy > 0)
			return (mlx->textures[NORTH_PATH]);
		return (mlx->textures[SOUTH_PATH]);
	}
	else
	{
		if (dx > 0)
			return (mlx->textures[WEST_PATH]);
		return (mlx->textures[EAST_PATH]);
	}
}

/*static void	draw_vertical_line(t_mlx *mlx, int x, int side, double distance,
		double dir[2], double wall_x)*/ 
static void	draw_vertical_line(t_mlx *mlx, int x, t_vertical_line *wall)
{
	int		wall_height;
	int		y;
	int		start;
	int		end;
	t_img	texture;
	double	texture_x;
	double	texture_y;
	int		color;
	double	step;
	double	tex_pos;
	int		index;
	char	*pixel;

	texture = get_texture(mlx, wall->side,
			wall->dir[X_POS], wall->dir[Y_POS]);
	texture_x = get_texture_x(wall->hit_position, texture, wall);
	wall_height = (int)(HEIGHT / (wall->distance + 0.0001));
	start = (HEIGHT / 2) - (wall_height / 2);
	end = (HEIGHT / 2) + (wall_height / 2);
	step = (double)texture.height / wall_height;
	tex_pos = 0;
	if (start < 0)
	{
		tex_pos = (double)(-start) * step;
		start = 0;
	}
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	pixel = mlx->img.addr + start * mlx->img.line_length
		+ x * (mlx->img.bits_per_pixel / 8);
	y = start;
	while (y < end)
	{
		texture_y = (int)tex_pos & (texture.height - 1);
		tex_pos += step;
		index = (int)texture_y * texture.line_length
			+ (int)texture_x * (texture.bits_per_pixel / 8);
		color = *(unsigned int *)(texture.addr + index);
		*(unsigned int *)pixel = color;
		pixel += mlx->img.line_length;
		y++;
	}
}

static double	hit_position(t_mlx *mlx, double distance,
		double dir[2], int side)
{
	double	wall_x;

	wall_x = 0;
	if (side == Y_POS)
		wall_x = mlx->map_data->player[X_POS] + distance * dir[X_POS];
	else
		wall_x = mlx->map_data->player[Y_POS] + distance * dir[Y_POS];
	wall_x -= floor(wall_x);
	return (wall_x);
}

/* STEPS
 *
 * 1) Obtain ray_angle
 * 2) With these angle, take cosine and sine
 * 3) Obtain ray distance between player and wall which has been hit
 * 4) Correct distance to avoid 'fisheye'
 * 5) Draw a vertical stripe*/
void	render_3d_scene(t_mlx *mlx)
{
	t_vertical_line	wall;
	int				x;
	double			ray_angle;

	x = 0;
	while (x < WIDTH)
	{
		ray_angle = (mlx->map_data->player_angle
				- (mlx->map_data->fov_angle / 2))
			+ ((double)x / (double)WIDTH) * mlx->map_data->fov_angle;
		wall.dir[X_POS] = cos(ray_angle);
		wall.dir[Y_POS] = sin(ray_angle);
		wall.distance = throw_ray(mlx, &wall.side,
				wall.dir[X_POS], wall.dir[Y_POS]);
		wall.hit_position = hit_position(mlx, wall.distance,
				wall.dir, wall.side);
		wall.distance *= cos(ray_angle - mlx->map_data->player_angle);
		draw_vertical_line(mlx, x, &wall);
		++x;
	}
}
