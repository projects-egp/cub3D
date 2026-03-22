/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_rgb_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:08:57 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/03/22 20:20:44 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	check_digit_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	return (1);
}

static int	check_strings(char **array)
{
	int	i;
	int	return_status;

	i = 0;
	return_status = 1;
	while (array[i] && return_status)
	{
		return_status = check_digit_chars(array[i]);
		++i;
	}
	if (i != RGB_VALUES)
		return_status = 0;
	if (!return_status)
	{
		ft_putendl_error("Error\nRGB integers format: 0,0,0");
		free_strings_array(array);
	}
	return (return_status);
}

static int	conversion(int *rgb_array, char **string_array)
{
	int	return_status;
	int	i;
	int	not_needed;

	return_status = 1;
	i = 0;
	not_needed = 0;
	while (i < RGB_VALUES)
	{
		rgb_array[i] = ft_atoi_protected(string_array[i], &not_needed);
		if (rgb_array[i] < 0 || rgb_array[i] > 255)
		{
			return_status = 0;
			break ;
		}
		++i;
	}
	if (!return_status)
		ft_putendl_error("Error\nColor values must be between 0 or 255");
	free_strings_array(string_array);
	return (return_status);
}

int	store_rgb_values(int identifier, char *info, t_map *file_data)
{
	char	**splited;

	splited = ft_split(info, ',');
	if (!splited || splited[0][0] == 0)
	{
		ft_putendl_error("Error\nMalloc failed");
		return (0);
	}
	if (!check_strings(splited))
		return (0);
	if ((identifier == 'C'
			&& !conversion(file_data->ceiling_color, splited))
		|| (identifier == 'F'
			&& !conversion(file_data->floor_color, splited)))
		return (0);
	return (1);
}
