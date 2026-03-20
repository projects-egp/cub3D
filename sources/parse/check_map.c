/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 18:52:55 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/03/20 20:22:05 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	check_map(t_map *data)
{
	if (data->parse_checklist < 6)
	{
		ft_putendl_error("Error\nFile has not complete data to print map");
		//Clean data stored
		return (0);
	}
	return (1);
}
