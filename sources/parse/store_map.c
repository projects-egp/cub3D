/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 18:52:55 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/11 15:54:27 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

/*This function is returned by read_data() to parse_main(). 
 * Here we will store and check map. In any case, we will return to parse_main()
 * and then close file descriptor from map filei. Doesn't matter if we return
 * succesfully or with some error found*/
int	store_map(t_map *map_data, t_list **map_lines)
{
	free_full_list_and_contents(map_lines);//debug
	//This is a debug line to be sure we clean everything okay and reach
	//this point succesfully
	//
	//
	//
	//store_map(data->map_data);//As did it on so_long
	return (1);
}
