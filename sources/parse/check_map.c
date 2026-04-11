/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 17:17:03 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/11 19:32:56 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static int	is_next_char_valid()
{
	if (c == 1 || c == 0 || ft_ischar(c))
		return (1);
	return (0);
}

static int	check_char(t_map *data, int y, int x, int last_line)
{
		//check up, don't worry, you started at second line
	if (data->map[y][x + 1] != 0)
		//checks right	
	if (y < last_line)
		//checks down
	if (x != 0)
		//cehcks left
}

static int	check_line(t_map *data, int y, int last_line)
{
	int	x;
	char	c;
	
	x = 0;
	while (data->map[y][x])
	{
		c = data->map[y][x];
		if ((c == '0' || ft_isalpha(c))
			&& !check_char(data, y, x, last_line))
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
			return (0);
		++y;
	}
	return (1);
}
