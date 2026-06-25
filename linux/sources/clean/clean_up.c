/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 22:00:30 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/09 15:10:08 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	clean_up(t_mlx *mlx_data)
{
	destroy_mlx_requested(mlx_data);
	clean_file_data(mlx_data->map_data);
	return ;
}
