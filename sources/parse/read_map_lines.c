/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 13:02:19 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/18 09:26:42 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

/*If len includes "\n", will be updated to avoid it if later is used as
 * map_data->width. That's the reason we do substr instead of strdup, too*/
static int	copy_line_and_add_to_list(char *line, t_list **map_lines,
		int len)
{
	char	*line_copy;

	if (len >= 1 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	line_copy = NULL;
	line_copy = ft_substr(line, 0, len);
	if (!line_copy || !add_new_line_to_list(line_copy, map_lines))
	{
		print_error(MALLOC_FAILED);
		return (0);
	}
	return (1);
}

/*First line of map must have '1' chars, ' ' space char 32 on ASCII, 
 * or new line char, nothing else.
 *
 * This function is also used on add_scene_data.c, to make sure 
 * map is not found before expected*/
int	is_first_map_line(char *line)
{
	int	len;

	len = 0;
	while (line[len])
	{
		if (line[len] == ' ' || line[len] == '1' || line[len] == '\n')
			++len;
		else
			return (0);
	}
	return (1);
}

/*From now on, (height && width) > 0. This means program is reading map*/
int	add_valid_first_map_line(char *line, t_map *file_data,
		t_list **map_lines)
{
	int	len;

	if (!is_first_map_line(line))
	{
		print_error(WRONG_CHAR_FOUND);
		free_full_list_and_contents(map_lines);
		return (0);
	}
	len = ft_strlen(line);
	if (!copy_line_and_add_to_list(line, map_lines, len))
		return (0);
	++file_data->height;
	file_data->width = len;
	return (1);
}

/*As long as a valid empty line cannot make problems to map, not only ascii 32
 * will be accepted, but also any other whitespace char. In lines with
 * at least one char != whitespace, a tab "'\t'" ascii 9 seems to be okay
 * but in code is just on char, so map could appear as valid but for program
 * would be not properly closed*/
static int	add_valid_empty_line(char *line, t_map *map_data,
		t_list **map_lines)
{
	int	len;

	len = ft_strlen(line);
	if (!copy_line_and_add_to_list(line, map_lines, len))
	{
		free_full_list_and_contents(map_lines);
		return (0);
	}
	++map_data->height;
	return (1);
}

/*After check all line, i = strlen. Includes "\n". This is corrected on
 * copy_line_and_add_to_list().
 * 
 * If (is_empty_line && parse_checklist == 6) means that 
 * line doesn't start with '\n', so map hasn't ended yet.
 * Is valid and must be stored*/
int	add_valid_map_line(char *line, t_map *file_data, t_list **map_lines)
{
	int	len;

	len = 0;
	if (is_empty_line(line))
		return (add_valid_empty_line(line, file_data, map_lines));
	while (line[len])
	{
		if (!is_valid_map_char(line[len], len, file_data))
		{
			free_full_list_and_contents(map_lines);
			return (0);
		}
		++len;
	}
	if (!check_first_and_last_chars(line, len)
		|| !copy_line_and_add_to_list(line, map_lines, len))
	{
		free_full_list_and_contents(map_lines);
		return (0);
	}
	++file_data->height;
	if (len > file_data->width)
		file_data->width = len;
	return (1);
}
