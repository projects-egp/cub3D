/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 18:52:55 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/05 19:35:14 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	store_map(t_map *map_data, t_list **map_lines)
{
	if (map_data->parse_checklist < 6)
	{
		ft_putendl_error("Error\nFile has not complete data to print map");
		//Clean data stored
		return (0);
	}
	free_full_list_and_contents(map_lines);//debug
	//This is a debug line to be sure we clean everything okay and reach
	//this point succesfully
	//
	//
	//
	//store_map(data->map_data);//As did it on so_long
	return (1);
}
