/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 17:17:03 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/14 17:00:28 by enrgil-p         ###   ########.fr       */
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

static int	check_line(t_map *data, int y, int last_line)
{
	int		x;
	char	c;

	x = 0;
	while (data->map[y][x])
	{
		c = data->map[y][x];
		if ((c == '0' || ft_isalpha(c))
			&& !check_orthogonal_next_chars(data, y, x, last_line))
			return (0);
		++x;
	}
	return (1);
}

/*check_map() is returned from open_file() to main(). It's last step from parse.
 * Here map is checked to be sure that a 0 or "spwan_orienation char" is not
 * surrounded by other char of these type or 1.
 *
 * Will start with second line, 
 * as long as first line was validated while reading*/
int	check_map(t_map *data)
{
	int	y;
	int	last_line;

	y = 1;
	last_line = data->height - 1;
	while (y < data->height)
	{
		if (!check_line(data, y, last_line))
		{
			clean_file_data(data);
			return (0);
		}
		++y;
	}
	return (1);
}
