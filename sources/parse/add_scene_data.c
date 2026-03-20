/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_scene_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:04:46 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/03/20 20:14:49 by enrgil-p         ###   ########.fr       */
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
	return (0);
}

static void	store_data(int identifier, char *info, t_map *data)
{
	if (identifier == 'C' || identifier == 'F')
	{
		//plit with ','
		//atoi and store
	}
	else if (identifier == 'N')
		data->north_path = ft_strdup(info);
	//HEY! START THINKING HOW TO FREE THIS IN LATER ERRORS AND
	//AT THE END OF EXECUTION
	else if (identifier == 'S')
		data->south_path = ft_strdup(info);
	else if (identifier == 'W')
		data->west_path = ft_strdup(info);
	else if (identifier == 'E')
		data->east_path = ft_strdup(info);
	return ;
}

int	add_scene_data(char *line, t_map *data)
{
	char	**array;

	array = ft_split(line, ' ');
	if (array[2] != NULL || array[2][0] != 0)
	{
		ft_putendl_error("Error\nExpected identifier + information");
		return (error_found(array));
	}
	if (!valid_identifier(array[0]))
		return (error_found(array));
	store_data(array[0][0], array[1], data);
	data->parse_checklist += 1;
	free_strings_array(array);
	return (1);
}
