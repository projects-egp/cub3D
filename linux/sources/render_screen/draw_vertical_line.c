/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 21:05:08 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/26 23:01:13 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static double	get_texture_x(double wall_x, t_img texture,
		t_wall *wall)
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

static int	get_pixel_color(t_img texture, t_vertical_line *line_data)
{
	double	texture_y;
	int		index;
	int		color;

	texture_y = (int)line_data->tex_pos & (texture.height - 1);
	line_data->tex_pos += line_data->step;
	index = (int)texture_y * texture.line_length
		+ (int)line_data->texture_x * (texture.bits_per_pixel / 8);
	color = *(unsigned int *)(texture.addr + index);
	return (color);
}

//Here we finally print vertical line, looking each time for a pixel
static void	put_pixels(t_mlx *mlx, int x, t_img texture,
		t_vertical_line *line)
{
	int		y;
	char	*pixel;

	pixel = mlx->img.addr + line->start * mlx->img.line_length
		+ x * (mlx->img.bits_per_pixel / 8);
	y = line->start;
	while (y < line->end)
	{
		*(unsigned int *)pixel = get_pixel_color(texture, line);
		pixel += mlx->img.line_length;
		++y;
	}
}

/*Norminette thinks that line 108 has a pointer before line.step.
 * Actually, it's a multiply operator.
 *
 * 	STEPS DONE:
 * 1) get texture to check and get vertical lines pixel from it
 * 2) get vertical line from texture ("texture_x"),
 * 	based on what vertical line from wall do we need
 * 3) get "wall_height" and then position to draw the vertical line on screen
 * 4) get steps ("step") to print the line one by one
 * 5) get start position at texture vertical line ("tex_pos").
 * 	If player is too close to drawed wall, this texture start position 
 * 	won't be the top of it,
 * 	but will be printed from top to bottom of the screen
 * */
void	draw_vertical_line(t_mlx *mlx, int x, t_wall *wall)
{
	int				wall_height;
	t_img			texture;
	t_vertical_line	line;

	texture = get_texture(mlx, wall->side,
			wall->dir[X_POS], wall->dir[Y_POS]);
	line.texture_x = get_texture_x(wall->hit_position, texture, wall);
	wall_height = (int)(HEIGHT / (wall->distance + 0.0001));
	line.start = (HEIGHT / 2) - (wall_height / 2);
	line.end = (HEIGHT / 2) + (wall_height / 2);
	line.step = (double)texture.height / wall_height;
	line.tex_pos = 0;
	if (line.start < 0)
	{
		line.tex_pos = (double)(-line.start) *line.step;
		line.start = 0;
	}
	if (line.end >= HEIGHT)
		line.end = HEIGHT - 1;
	put_pixels(mlx, x, texture, &line);
}
