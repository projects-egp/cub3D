/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:41:10 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/08 16:18:40 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

//Adde here this enum to avoid confusion with other enums. 
//These values are used only at check_stored_map.c
typedef enum e_check_map_functions
{
	CHECK_CLOSE_MAP,
	FILL_EMPTY_CORNERS
}	t_check_map_functions;
//
//
/*	*	*	 PARSE FUNCTIONS	*	*	*/

int	open_file(char *cub_file_path, t_map *file_data);
int	read_data(t_map *data, int fd);
int	check_stored_map(t_map *map_data, int requested_function);
int	is_empty_line(char *line);
//
/*	*	 map_lines_utils.c	*	*/
int	checklist(t_map *file_data);
//
/*	scene data: texture paths and color for ceiling and floor	*/
int	add_scene_data(char *line, t_map *data);
int	store_rgb_values(int identifier, char *info, t_map *file_data);
//
/*	map lines: get a line, check it, keep on a list, later store together*/
int	add_valid_first_map_line(char *line, t_map *file_data,
		t_list **map_lines);
int	is_first_map_line(char *line);
int	add_valid_map_line(char *line, t_map *file_data, t_list **map_lines);
int	store_map(t_map *map_data, t_list **map_lines);
//
/*	*	 map_lines_utils.c	*	*/
int	add_new_line_to_list(char *line, t_list **map_lines_list);
int	is_valid_map_char(int c, int x_position, t_map *map_data);
int	check_first_and_last_chars(char *line, int len);

#endif
