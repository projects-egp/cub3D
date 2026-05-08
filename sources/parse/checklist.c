/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:47:02 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/08 17:08:34 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	already_found(char identifier, t_map *file_data)
{
	if (identifier == 'N' && !file_data->parse_checklist[FOUND_NO])
		return (0);
	else if (identifier == 'E' && !file_data->parse_checklist[FOUND_EA])
		return (0);
	else if (identifier == 'S' && !file_data->parse_checklist[FOUND_SO])
		return (0);
	else if (identifier == 'W' && !file_data->parse_checklist[FOUND_WE])
		return (0);
	else if (identifier == 'C' && !file_data->parse_checklist[FOUND_C])
		return (0);
	else if (identifier == 'F' && !file_data->parse_checklist[FOUND_F])
		return (0);
	return (1);
}

int	checklist(t_map *file_data)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (i < CHECKLIST_SIZE)
		result += file_data->parse_checklist[i];
	return (result);
}
