/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:11:35 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/03/19 18:28:32 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_empty_line(char *line, t_mlx *data)
{
	int	len;
	int	i;

	len = ft_strlen(line);
	i = 0;
	while (i < len)
	{
		if (!ft_isspace(&line[i]))
			return (1);
		++i;
	}
	if (data->map->parse_checklist >= 6 && len > data->map->longest_len_line)
		data->map->longest_len_line = len;
	return (0);
}

int	read_data(char *cub_file_path, t_mlx *data, int fd)
{
	char	*line_read;

	while (1)
	{
		line_read = safe_call_to_get_next_line(fd);
		if (!line_read)
			break ;
		//Check line: is it only whitespace?
		//Have some expected data?
		//Have more things than expected by some element?
		//Map has been found to soon?
	}
	return (check_data(data));
	//Read information
	//Read map
}
