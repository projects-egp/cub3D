/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:08:46 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/05 11:55:51 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	key_pressed(int key, t_mlx *mlx)
{
	if (key == 53 || key == 65307)
		close_program(mlx, 0);
	if (key == 13 || key == 119)
		mlx->k_w = 1;
	else if (key == 1 || key == 115)
		mlx->k_s = 1;
	else if (key == 0 || key == 97)
		mlx->k_a = 1;
	else if (key == 2 || key == 100)
		mlx->k_d = 1;
	else if (key == 123 || key == 65361)
		mlx->k_l = 1;
	else if (key == 124 || key == 65363)
		mlx->k_r = 1;
	return (0);
}

int	key_released(int key, t_mlx *mlx)
{
	if (key == 13 || key == 119)
		mlx->k_w = 0;
	else if (key == 1 || key == 115)
		mlx->k_s = 0;
	else if (key == 0 || key == 97)
		mlx->k_a = 0;
	else if (key == 2 || key == 100)
		mlx->k_d = 0;
	else if (key == 123 || key == 65361)
		mlx->k_l = 0;
	else if (key == 124 || key == 65363)
		mlx->k_r = 0;
	return (0);
}
