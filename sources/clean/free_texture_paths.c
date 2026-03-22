/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 15:03:20 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/03/22 15:26:46 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

void	free_texture_paths(char *texture_paths[4])
{
	int	i;

	i = 0;
	while (i < TEXTURE_PATHS)
	{
		if (texture_paths[i] != NULL)
			free(texture_paths[i]);
		++i;
	}
	return ;
}
