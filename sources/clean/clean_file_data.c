/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_file_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 15:03:20 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/04 20:20:35 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	free_texture_paths(char **texture_paths)
{
	int	i;

	i = 0;
	while (i < TEXTURE_PATHS)
	{
		if (texture_paths[i])
		{
			free(texture_paths[i]);
			texture_paths[i] = NULL;
		}
		++i;
	}
	return ;
}

void	clean_file_data(t_map *file_data)
{
	free_texture_paths(file_data->texture_paths);
	//Other data to free, for example map
	return ;
}
