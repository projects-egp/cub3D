/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 13:02:19 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/05 19:55:31 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

/*If len includes "\n", will be updated to avoid it if later is used as
 * map_data->width. That's the reason we do substr instead of strdup, too*/
static int	copy_line_and_add_to_list(char *line, t_list **map_lines,
		int *len)
{
	char	*line_copy;

	if (line[*len] == '\n')
		*len -= 1;
	line_copy = NULL;
	line_copy = ft_substr(line, 0, *len);
	if (!line_copy || !add_new_line_to_list(line_copy, map_lines))
	{
		ft_putendl_error(MALLOC_FAILED);
		return (0);
	}
	return (1);
}

/*First line of map must have '1' chars, ' ' space char 32 on ASCII, 
or new line char, nothing else. From now on, (height && width) > 0*/
int	add_valid_first_map_line(char *line, t_map *file_data,
		t_list **map_lines)
{
	int	len;

	len = 0;
	while (line[len])
	{
		if (line[len] == ' ' || line[len] == '1' || line[len] == '\n')
			++len;
		else
		{
			ft_putendl_error(WRONG_CHAR_FOUND);
			free_full_list_and_contents(map_lines);
			return (0);
		}
	}
	if (!copy_line_and_add_to_list(line, map_lines, &len))
		return (0);
	++file_data->height;
	file_data->width = len;
	return (1);
}

/*After check all line, i = strlen. Includes "\n". This is corrected on
copy_line_and_add_to_list()*/
int	add_valid_map_line(char *line, t_map *file_data, t_list **map_lines)
{
	int	len;

	len = 0;
	while (line[len])
	{
		if (!is_valid_map_char(line[len], len, file_data))
		{
			free_full_list_and_contents(map_lines);
			return (0);
		}
		++len;
	}
	if (!copy_line_and_add_to_list(line, map_lines, &len))
		return (0);
	++file_data->height;
	if (len > file_data->width)
		file_data->width = len;
	return (1);
}
