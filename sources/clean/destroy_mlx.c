/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:03:42 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/11 20:08:15 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	remove_images(t_mlx *mlx)
{
	if (mlx->img.img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	return ;
}

void	destroy_mlx_requested(t_mlx *mlx)
{
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	remove_images(mlx);
	if (mlx->mlx_ptr)
	{
# ifdef __linux__
		mlx_destroy_display(mlx->mlx_ptr);
# endif
		free(mlx->mlx_ptr);
	}
	return ;
}
