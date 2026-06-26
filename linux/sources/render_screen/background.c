/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:41:33 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/26 20:14:13 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

/*Operator | is used because changes a 0 bit from result to 1 in case of 
 * bits valued as 1 from decimal_value*/
static uint32_t	get_color_value(int *decimal_value)
{
	uint32_t	result;

	result = decimal_value[RED] << 16 | decimal_value[GREEN] << 8
		| decimal_value[BLUE];
	return (result);
}

static void	draw_loop(t_mlx *mlx, int limit_to_draw, uint32_t color, int *y)
{
	uint32_t		*row;
	int				x;

	while (*y < limit_to_draw)
	{
		row = (uint32_t *)(mlx->img.addr + (*y) * mlx->img.line_length);
		x = 0;
		while (x < WIDTH)
			row[x++] = color;
		++(*y);
	}
	return ;
}

void	draw_background(t_mlx *mlx)
{
	int				y;
	static uint32_t	ceiling_color;
	static uint32_t	floor_color;

	if (!ceiling_color)
		ceiling_color = get_color_value(mlx->map_data->ceiling_color);
	if (!floor_color)
		floor_color = get_color_value(mlx->map_data->floor_color);
	y = 0;
	draw_loop(mlx, (HEIGHT / 2), ceiling_color, &y);
	draw_loop(mlx, HEIGHT, floor_color, &y);
}
