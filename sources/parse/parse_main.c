/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 18:14:32 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/11 18:00:08 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	init_map_data(t_map *map_data)
{
	ft_bzero((void *)map_data->texture_paths,
		(sizeof(char *) * (TEXTURE_PATHS + 1)));
	ft_bzero((void *)map_data->floor_color, (sizeof(int) * RGB_VALUES));
	ft_bzero((void *)map_data->ceiling_color, (sizeof(int) * RGB_VALUES));
	map_data->parse_checklist = 0;
	map_data->map = NULL;
	ft_bzero((void *)map_data->player, (sizeof(int) * POSITION));
	map_data->spawn_orientation = 0;
	map_data->height = 0;
	map_data->width = 0;
	return ;
}

/*Files are not specifically required to be on maps/, 
 *so it is not checked*/
static int	file_format(char *file_path)
{
	//Note to remmeber you must decide if file must been checked strictly
	char	*first_dot_position;

	if (ft_strnstr(file_path, ".cub", 4))
	{
		print_error(FILE_NAMED_DOTCUB);
		return (0);
	}
	first_dot_position = ft_strchr(file_path, '.');
	if (!first_dot_position
		|| !ft_strnstr(first_dot_position, ".cub", 4)
		|| first_dot_position[4] != 0)
	{
		print_error(FILE_FORMAT_ERROR);
		return (0);
	}
	return (1);
}

int	open_file(char *cub_file_path, t_map *file_data)
{
	int		fd;
	int		read_status;

	if (!file_format(cub_file_path))
		return (0);
	fd = open(cub_file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nFailed trying to open ", 2);
		ft_putendl_error(cub_file_path);
		return (0);
	}
	init_map_data(file_data);
	read_status = read_data(file_data, fd);
	close(fd);
	if (!read_status)
	{
		clean_file_data(file_data);
		return (0);
	}
	return (check_map(file_data));
}
