/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 10:54:46 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/09 11:52:37 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	link_error_message(t_mlx *mlx, int index)
{
	ft_putendl_error("Error");
	ft_putstr_fd(mlx->map_data->texture_paths[index], 2);
	ft_putendl_error(" failed while trying to link it. Check this file");
	return ;
}

static void	init_pointers(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < TEXTURE_PATHS)
		mlx->textures[i++].img_ptr = NULL;
}

void	link_images(t_mlx *mlx)
{
	int	i;

	i = 0;
	init_pointers(mlx);
	while (i < TEXTURE_PATHS)
	{
		mlx->textures[i].img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
				mlx->map_data->texture_paths[i],
				&mlx->textures[i].width,
				&mlx->textures[i].height);
		if (!mlx->textures[i].img_ptr)
		{
			link_error_message(mlx, i);
			close_program(mlx, ERROR_CLOSE);
		}
		mlx->textures[i].addr = mlx_get_data_addr(mlx->textures[i].img_ptr,
				&mlx->textures[i].bits_per_pixel,
				&mlx->textures[i].line_length,
				&mlx->textures[i].endian);
		++i;
	}
	return ;
}
