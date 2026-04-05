/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 13:02:19 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/05 13:57:40 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	valid_first_map_line(char *line, t_map *file_data, t_list **map_lines)
{
	int	i;
	char	*line_copy;

	i = 0;
	line_copy = NULL;
	if (!isspace(line[i]) && line[i] != '1')
	{
		//error message wrong chars
		return (0);
	}
	line_copy = ft_strdup(line);
	if (!line_copy)
	{
		ft_putendl_error(MALLOC_FAILED);
		return (0);
	}
	add_to_map_lines();
}
