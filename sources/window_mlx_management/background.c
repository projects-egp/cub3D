/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:41:33 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/26 19:27:10 by enrgil-p         ###   ########.fr       */
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

void	draw_background(t_mlx *mlx)
{
	int				x;
	int				y;
	static uint32_t	ceiling_color;
	static uint32_t	floor_color;

	y = 0;
	if (!ceiling_color)
		ceiling_color = get_color_value(mlx->map_data->ceiling_color);
	if (!floor_color)
		floor_color = get_color_value(mlx->map_data->floor_color);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				my_pixel_put(&mlx->img, x, y, ceiling_color);
			else
				my_pixel_put(&mlx->img, x, y, floor_color);
			x++;
		}
		y++;
	}
//	draw_walls(mlx);
}
