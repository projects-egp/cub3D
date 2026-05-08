/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:47:02 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/08 13:04:31 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	scene_data_found(t_map *file_data)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (i < CHECKLIST_SIZE)
		result += file_data->parse_checklist[i];
	return (result);
}
