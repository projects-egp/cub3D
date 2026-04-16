/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 17:17:03 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/16 18:14:11 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	is_valid_char(char c)
{
	if (c == '1' || c == '0' || ft_isalpha(c))
		return (1);
	return (0);
}

/*Check in clockwise (up, right, down, left).
 * Map is consider valid in case of empty char in corners*/
static int	check_orthogonal_next_chars(t_map *data, int y, int x,
		int last_line)
{
	if (!is_valid_char(data->map[y - 1][x]))
		return (0);
	if (data->map[y][x + 1] != 0 && !is_valid_char(data->map[y][x + 1]))
		return (0);
	if (y < last_line && !is_valid_char(data->map[y + 1][x]))
		return (0);
	if (x != 0 && !is_valid_char(data->map[y][x - 1]))
		return (0);
	return (1);
}

static int	check_line(t_map *data, int y, int last_line, int requested)
{
	int		x;
	char	c;

	x = 0;
	while (x < data->width - 1)
	{
		c = data->map[y][x];
		if (requested == CHECK_CLOSE_MAP && c != 0 
			&& (c == '0' || ft_isalpha(c))
			&& !check_orthogonal_next_chars(data, y, x, last_line))
			return (0);
		else if (requested == FILL_EMPTY_CORNERS
			&& !is_valid_char(data->map[y][x]))
			data->map[y][x] = '1';
		++x;
	}
	return (1);
}

/*check_map() is returned from open_file() to main().
 * 
 * Two last steps from parse. 
 * 
 * First one: map is checked to be sure that 
 * a '0' or "spwan_orienation char" is not surrounded by other char 
 * of these type or '1'.
 *
 * Second one: check in each '0' or "spawn_orientiation_char"
 * if diagonal next chars are whitespace. If some space is found there,
 * will be changed to 1. This is done in order to avoid player escaping map
 * later. 
 * Why is done in a second step? To make it sure that map is valid before
 * changing chars.
 *
 * Will start with second line, 
 * as long as first line was validated while reading*/
int	check_map(t_map *data, int requested_function)
{
	int	y;
	int	last_line;

	y = 1;
	last_line = data->height - 1;
	while (y < data->height)
	{
		if (requested_function == CHECK_CLOSE_MAP
			&& !check_line(data, y, last_line, requested_function))
		{
			print_error(MAP_NOT_CLOSED);
			clean_file_data(data);
			return (0);
		}
		else if (requested_function == FILL_EMPTY_CORNERS)
			check_line(data, y, last_line, requested_function);
		if (++y == data->height && requested_function == CHECK_CLOSE_MAP)
		{
			y = 0;
			++requested_function;
		}
	}
	return (1);
}
