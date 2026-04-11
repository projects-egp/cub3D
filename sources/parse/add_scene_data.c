/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_scene_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:04:46 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/11 17:59:17 by enrgil-p         ###   ########.fr       */
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
	print_error(IDENTIFIER_ERROR);
	return (0);
}

/*char *path_to_allocated used to work, although it was origin for leaks.
 * To keep this clean design was needed a "char **" pointer
 * and reference (&) to it the final destination of ft_strdup's malloc*/
static int	store_data(int identifier, char *info, t_map *file_data)
{
	char	**path_to_allocate;

	if (identifier == 'C' || identifier == 'F')
	{
		if (!store_rgb_values(identifier, info, file_data))
			return (0);
		return (1);
	}
	if (identifier == 'N')
		path_to_allocate = &file_data->texture_paths[NORTH_PATH];
	if (identifier == 'S')
		path_to_allocate = &file_data->texture_paths[SOUTH_PATH];
	if (identifier == 'W')
		path_to_allocate = &file_data->texture_paths[WEST_PATH];
	if (identifier == 'E')
		path_to_allocate = &file_data->texture_paths[EAST_PATH];
	*path_to_allocate = ft_strdup(info);
	if (*path_to_allocate == NULL)
	{
		print_error(MALLOC_FAILED);
		return (0);
	}
	return (1);
}

int	add_scene_data(char *line, t_map *file_data)
{
	char	**array;

	if (!is_empty_line(line))
	{
		array = ft_split_whitespace(line);
		if (!array)
		{
			print_error(MALLOC_FAILED);
			return (0);
		}
		if (array[1] == NULL || array[2] != NULL)
		{
			print_error(SCENE_DATA_ERROR);
			return (error_found(array));
		}
		if (!valid_identifier(array[0])
			|| !store_data(array[0][0], array[1], file_data))
			return (error_found(array));
		file_data->parse_checklist += 1;
		free_strings_array(array);
	}
	return (1);
}
