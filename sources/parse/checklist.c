/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 12:47:02 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/02 18:38:20 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	update_checklist(t_map *file_data, int position)
{
	file_data->parse_checklist[position] = 1;
	return (1);
}

int	check_if_already_found(char identifier, t_map *file_data)
{
	if (identifier == 'N' && !file_data->parse_checklist[FOUND_NO])
		return (update_checklist(file_data, FOUND_NO));
	else if (identifier == 'E' && !file_data->parse_checklist[FOUND_EA])
		return (update_checklist(file_data, FOUND_EA));
	else if (identifier == 'S' && !file_data->parse_checklist[FOUND_SO])
		return (update_checklist(file_data, FOUND_SO));
	else if (identifier == 'W' && !file_data->parse_checklist[FOUND_WE])
		return (update_checklist(file_data, FOUND_WE));
	else if (identifier == 'C' && !file_data->parse_checklist[FOUND_C])
		return (update_checklist(file_data, FOUND_C));
	else if (identifier == 'F' && !file_data->parse_checklist[FOUND_F])
		return (update_checklist(file_data, FOUND_F));
	print_error(DUPLICATED_IDENTIFIER);
	return (0);
}

int	checklist(t_map *file_data)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (i < CHECKLIST_SIZE)
	{
		result += file_data->parse_checklist[i];
		++i;
	}
	return (result);
}
