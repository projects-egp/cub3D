/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 18:14:32 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/03/20 18:44:37 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	init_other_data(t_mlx *data)
{
	//Init other data
	(void)data;//debug
	return (1);
}

static void	init_map_data(t_map *map)
{
	map->north_path = NULL;
	map->east_path = NULL;
	map->south_path = NULL;
	map->west_path = NULL;
	map->floor_color[RED] = 0;
	map->floor_color[GREEN] = 0 ;
	map->floor_color[BLUE] = 0;
	map->ceiling_color[RED] = 0;
	map->ceiling_color[GREEN] = 0;
	map->ceiling_color[BLUE] = 0;
	map->parse_checklist = 0;
	map->map = NULL;
	map->longest_len_line = 0;
	map->last_line = 0;
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

	if (!file_format(cub_file_path))
		return (0);
	fd = open(cub_file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nFailed trying to open ", 2);
		ft_putendl_error(cub_file_path);
		return (0);
	}
	init_map_data(data->map_data);
	read_status = read_data(data, fd);
	//Read line by line and store in a list, or at least this is what
	//you did on so_long
	//But this time, would be better to read a line, and see what it has.
	//Do this to get all data. And later you can work with a list for map...
	//Or not... Just think about it
	close(fd);
	if (!read_status)
		return (0);
	//store_map(data->map_data);//As did it on so_long
	return (init_other_data(data));
}
