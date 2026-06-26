/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:08:46 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/26 11:42:44 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

//Both functions of this file uses <X11/keysym.h> to identify keys, as long as
//program is expected to be executed with X11 at Ubuntu Linux OS
int	key_pressed(int key, t_mlx *mlx)
{
	if (key == XK_Escape)
		close_program(mlx, SUCCESS_CLOSE);
	if (key == XK_w)
		mlx->key[W_KEY] = 1;
	else if (key == XK_s)
		mlx->key[S_KEY] = 1;
	else if (key == XK_a)
		mlx->key[A_KEY] = 1;
	else if (key == XK_d)
		mlx->key[D_KEY] = 1;
	else if (key == XK_Left)
		mlx->key[LEFT_KEY] = 1;
	else if (key == XK_Right)
		mlx->key[RIGHT_KEY] = 1;
	return (0);
}

int	key_released(int key, t_mlx *mlx)
{
	if (key == XK_w)
		mlx->key[W_KEY] = 0;
	else if (key == XK_s)
		mlx->key[S_KEY] = 0;
	else if (key == XK_a)
		mlx->key[A_KEY] = 0;
	else if (key == XK_d)
		mlx->key[D_KEY] = 0;
	else if (key == XK_Left)
		mlx->key[LEFT_KEY] = 0;
	else if (key == XK_Right)
		mlx->key[RIGHT_KEY] = 0;
	return (0);
}
