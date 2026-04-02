/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 22:00:30 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/02 21:52:47 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	clean_up(t_mlx *mlx_data)
{
	printf("in clean --->%s<---\n", mlx_data->map_data->texture_paths[WEST_PATH]);//debug
	//clean_file_data(mlx_data->map_data);
	printf("in clean --->%s<---\n", mlx_data->map_data->texture_paths[WEST_PATH]);//debug
	return ;
}
