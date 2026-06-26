/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 15:03:42 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/09 11:50:23 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	remove_images(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < TEXTURE_PATHS)
	{
		if (mlx->textures[i].img_ptr)
			mlx_destroy_image(mlx->mlx_ptr, mlx->textures[i].img_ptr);
		++i;
	}
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
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	return ;
}
