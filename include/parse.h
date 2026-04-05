/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:41:10 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/05 14:47:20 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "general.h"

int	open_file(char *cub_file_path, t_map *file_data);
int	read_data(t_map *data, int fd);
int	is_empty_line(char *line, t_map *file_data);
//
/*	scene data: texture paths and color for ceiling and floor	*/
int	add_scene_data(char *line, t_map *data);
int	store_rgb_values(int identifier, char *info, t_map *file_data);
//
/*	map lines: get a line, check it, keep on a list, later store together*/
int	valid_first_map_line(char *line, t_map *file_data, t_list **map_lines)
int	add_new_line(char *line, t_list **map_lines_list);
int	check_map(t_map *data);

#endif
