/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_scene_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:04:46 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/04 18:40:16 by enrgil-p         ###   ########.fr       */
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
	char	**path_to_allocate;

	if (identifier == 'C' || identifier == 'F')
	{
		if (!store_rgb_values(identifier, info, file_data))
			return (0);
		return (1);
	}
	//LEAK HERE. I don't understand: 
	//this strdup must be free here to avoid leak. But then I lose the str
	//If i don't free, I have data in other functions.
	//
	//Doesn't matter if I don't free at the end of execution:
	//leak still there
	if (identifier == 'N')
		path_to_allocate = &file_data->texture_paths[NORTH_PATH];
	if (identifier == 'S')
		path_to_allocate = &file_data->texture_paths[SOUTH_PATH];
		//file_data->texture_paths[SOUTH_PATH] = path_to_allocate;
	if (identifier == 'W')
		path_to_allocate = &file_data->texture_paths[WEST_PATH];
		//file_data->texture_paths[WEST_PATH] = path_to_allocate;
	if (identifier == 'E')
		path_to_allocate = &file_data->texture_paths[EAST_PATH];
		//file_data->texture_paths[EAST_PATH] = path_to_allocate;
	*path_to_allocate = ft_strdup(info);
	if (*path_to_allocate == NULL)
	{
		ft_putendl_error("Error\nMalloc failed");
		return (0);
	}
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
	if (array[2] != NULL || array[1] == NULL)
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
