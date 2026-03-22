/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_scene_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:04:46 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/03/22 19:05:21 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	error_found(char **array)
{
	free_strings_array(array);
	return (0);
}

static int	valid_identifier(char *identifier)
{
	if ((identifier[0] == 'F' || identifier[0] == 'C') && identifier[1] == 0)
		return (1);
	else if ((identifier[0] == 'N' || identifier[0] == 'S')
		&& identifier[1] == 'O' && identifier[2] == 0)
		return (1);
	else if (identifier[0] == 'W' && identifier[1] == 'E' && identifier[2] == 0)
		return (1);
	else if (identifier[0] == 'E' && identifier[1] == 'A' && identifier[2] == 0)
		return (1);
	ft_putendl_error("Error\nFound some wrong identifier");
	return (0);
}

static int	store_data(int identifier, char *info, t_map *file_data)
{
	char	*path_to_allocate;

	if ((identifier == 'C' || identifier == 'F')
		&& !store_rgb_values(identifier, info, file_data))
		return (0);
	else
		return (1);
	path_to_allocate = ft_strdup(info);
	if (!path_to_allocate)
	{
		ft_putendl_error("Error\nMalloc failed");
		return (0);
	}
	if (identifier == 'N')
		file_data->texture_paths[NORTH_PATH] = path_to_allocate;
	else if (identifier == 'S')
		file_data->texture_paths[SOUTH_PATH] = path_to_allocate;
	else if (identifier == 'W')
		file_data->texture_paths[WEST_PATH] = path_to_allocate;
	else if (identifier == 'E')
		file_data->texture_paths[EAST_PATH] = path_to_allocate;
	return (1);
}

int	add_scene_data(char *line, t_map *file_data)
{
	char	**array;

	array = ft_split_whitespace(line);
	if (!array)
	{
		ft_putendl_error("Error\nMalloc failed");
		return (0);
	}
	if (array[2] != NULL/* || array[2][0] != 0*/)//What happen if WEpath?
	{
		ft_putendl_error("Error\nExpected identifier + information");
		return (error_found(array));
	}
	if (!valid_identifier(array[0])
		|| !store_data(array[0][0], array[1], file_data))
		return (error_found(array));
	file_data->parse_checklist += 1;
	free_strings_array(array);
	return (1);
}
