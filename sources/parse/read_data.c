/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:11:35 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/02 21:37:30 by enrgil-p         ###   ########.fr       */
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

int	read_data(t_map *file_data, int fd)
{
	char	*line_read;

	while (1)
	{
		line_read = safe_call_to_get_next_line(fd, CONTINUE_READING);
		if (!line_read)
			break ;
		if (file_data->parse_checklist < 6
			&& !is_empty_line(line_read, file_data)
			&& !add_scene_data(line_read, file_data))
		{
			return (error_found(line_read, fd));
		}
			//Check what data is here
			//Have some expected data?
			//Have more things than expected by some element?
			//Map has been found to soon?
		//else if (!is_empty_line(line_read, data))
			//This is a map line with some chars
		//else
			//A line on map only with whitespace,
			//store it and later we will change it to
			//longest_len_line of 0 or whitespace
		free(line_read);
	}//Read line by line and store in a list, or at least this is what
	//you did on so_long
	//But this time, would be better to read a line, and see what it has.
	//Do this to get all data. And later you can work with a list for map...
	//Or not... Just think about it
	return (1);
}
