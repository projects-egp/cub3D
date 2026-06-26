/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:08:46 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/05 21:10:54 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	key_pressed(int key, t_mlx *mlx)
{
	if (key == 53 || key == 65307)
		close_program(mlx, SUCCESS_CLOSE);
	if (key == 13 || key == 119)
		mlx->key[W_KEY] = 1;
	else if (key == 1 || key == 115)
		mlx->key[S_KEY] = 1;
	else if (key == 0 || key == 97)
		mlx->key[A_KEY] = 1;
	else if (key == 2 || key == 100)
		mlx->key[D_KEY] = 1;
	else if (key == 123 || key == 65361)
		mlx->key[LEFT_KEY] = 1;
	else if (key == 124 || key == 65363)
		mlx->key[RIGHT_KEY] = 1;
	return (0);
}

int	key_released(int key, t_mlx *mlx)
{
	if (key == 13 || key == 119)
		mlx->key[W_KEY] = 0;
	else if (key == 1 || key == 115)
		mlx->key[S_KEY] = 0;
	else if (key == 0 || key == 97)
		mlx->key[A_KEY] = 0;
	else if (key == 2 || key == 100)
		mlx->key[D_KEY] = 0;
	else if (key == 123 || key == 65361)
		mlx->key[LEFT_KEY] = 0;
	else if (key == 124 || key == 65363)
		mlx->key[RIGHT_KEY] = 0;
	return (0);
}
