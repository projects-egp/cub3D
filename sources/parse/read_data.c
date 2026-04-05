/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:11:35 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/05 15:07:36 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	is_empty_line(char *line, t_map *file_data)
{
	int	len;
	int	i;

	len = ft_strlen(line);
	i = 0;
	while (i < len)
	{
		if (!ft_isspace(line[i]))
			return (0);
		++i;
	}
	//Maybe is a good idea to remove lines BELOW
	if (file_data->parse_checklist >= 6 && len > file_data->longest_len_line)
		file_data->longest_len_line = len;
	return (1);
}

static int	error_found(char *line, int fd)
{
	free(line);
	safe_call_to_get_next_line(fd, FAIL_HAPPENED);
	return (0);
}

static int	reading_scene_data(char *line_read, t_map *file_data)
{
	if (!is_empty_line(line_read, file_data)
		&& !add_scene_data(line_read, file_data))
		return (0);
	return (1);
}

static int	reading_map(char *line_read, t_map *file_data)
{
	if (file_data->parse_checklist == 6
		&& !is_empty_line(line_read, file_data)
		&& !valid_first_map_line(line_read, file_data, &map_lines))
		return (0);
	else if (file_data->parse_checklist > 7 && line_read[0] == '\n')
	{
		//error message: empty line inside map
		//free list. Okay, this is expecting a case of get this error
		//while still reading. Another way is to check it later
		return (0);
	}
	else if (file_data->parse_checklist > 6 && !valid_map_line())
		return (0);
	return (1);
}

int	read_data(t_map *file_data, int fd)
{
	char	*line_read;
	t_list	*map_lines;

	map_lines = NULL;
	while (1)
	{
		line_read = safe_call_to_get_next_line(fd, CONTINUE_READING);
		if (!line_read)
			break ;
		if (file_data->parse_checklist < 6
			&& !reading_scene_data(line_read, file_data))
			return (error_found(line_read, fd));
		else if (file_data->parse_checklist >= 6
			&& !reading_map(line_read, file_data))
			return (error_found(line_read, fd));
		free(line_read);
	}
	//Check HERE if checklist < 6, or bring back check_map() to this return
	//	return (0);
	return (1);
}
