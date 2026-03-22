/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 18:14:32 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/03/22 17:09:39 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	init_other_data(t_mlx *data, t_map *file_data)
{
	data->map_data = file_data;
	return (1);
}

static void	init_map_data(t_map *map_data)
{
	ft_bzero((void *)map_data->texture_paths,
		(sizeof(char *) * (TEXTURE_PATHS + 1)));
	ft_bzero((void *)map_data->floor_color, (sizeof(int) * RGB_VALUES));
	ft_bzero((void *)map_data->ceiling_color, (sizeof(int) * RGB_VALUES));
	map_data->parse_checklist = 0;
	map_data->map = NULL;
	map_data->longest_len_line = 0;
	map_data->last_line = 0;
	return ;
}

/*Files are not specifically required to be on maps/, 
 *so it is not checked*/
static int	file_format(char *file_path)
{
	char	*first_dot_position;

	if (ft_strnstr(file_path, ".cub", 4))
	{
		ft_putendl_error("Error\nGood format, but file has no name");
		return (0);
	}
	first_dot_position = ft_strchr(file_path, '.');
	if (!first_dot_position
		|| !ft_strnstr(first_dot_position, ".cub", 4)
		|| first_dot_position[4] != 0)
	{
		ft_putendl_error("Error\nExpected file format: <name>.cub");
		return (0);
	}
	return (1);
}

int	open_file(char *cub_file_path, t_mlx *data)
{
	int	fd;
	int	read_status;
	t_map	file_data;

	if (!file_format(cub_file_path))
		return (0);
	fd = open(cub_file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nFailed trying to open ", 2);
		ft_putendl_error(cub_file_path);
		return (0);
	}
	init_map_data(&file_data);
	read_status = read_data(&file_data, fd);
	//Read line by line and store in a list, or at least this is what
	//you did on so_long
	//But this time, would be better to read a line, and see what it has.
	//Do this to get all data. And later you can work with a list for map...
	//Or not... Just think about it
	close(fd);
	if (!read_status)
	{
		clean_file_data(&file_data);
		return (0);
	}
	//store_map(data->map_data);//As did it on so_long
	return (init_other_data(data, &file_data));
}
