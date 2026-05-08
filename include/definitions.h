/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:33:05 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/08 19:03:36 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

//
/*	*	*	* ERROR MESSAGES DEFINED *	*	*	*/
//
//
/*	*	general messages	*	*/
# define MALLOC_FAILED "Malloc failed"
# define EXPECTED_USAGE "Expected usage: ./cub3D [filename].cub"
//
/*	*	parse error messages	*	*/
//
//	file name
# define FILE_FORMAT_ERROR "Expected file format: <name>.cub"
# define FILE_NAMED_DOTCUB "Good file format, but file has no name"
//
//	scene data: textures
# define SCENE_DATA_ERROR "Expected scene data: identifier + information"
# define IDENTIFIER_ERROR "Found wrong identifier for scene data"
# define DUPLICATED_IDENTIFIER "Found duplicated identifier"
//
//	scene data: ceiling and floor colors
# define RGB_VALUES_CONVERSION "Cannot convert RGB values, non-digit char found"
# define NOT_THREE_RGB_VALUES "Expected three RGB values for ceiling and floor"
# define COLOR_VALUE_LIMITS "RGB values must be integers between 0 and 255"
//
//	scene_data: map
# define EXPECTED_MAP "While searching first map's line, found unexpected char"
# define UNCOMPLETE_DATA "Uncomplete file. It must have scene data and a map"
# define MAP_IS_NOT_LAST_ELEMENT "Map must be last element on file"
# define TWO_PLAYER_POSITIONS "Map must have just one spawn position"
# define WRONG_CHAR_FOUND "Found wrong char inside map content"
# define MAP_NOT_CLOSED "Map is not properly closed by walls"
# define MAP_WITHOUT_SPAWN "Map has no spawn position for player"
# define NEW_LINE_INSIDE_MAP "Found new line inside map content"
//
//	/	/	/	/	/	/	/	/	//
//
//
/*	*	*	*   ENUMS AND STRUCTS	*	*	*	*/
//

typedef enum e_rgb_values
{
	RED = 0,
	GREEN,
	BLUE,
	RGB_VALUES
}	t_rgb_values;

typedef enum e_texture_paths
{
	NORTH_PATH = 0,
	EAST_PATH,
	SOUTH_PATH,
	WEST_PATH,
	TEXTURE_PATHS
}	t_texture_paths;

typedef enum e_player_position
{
	X_POS = 0,
	Y_POS,
	POSITION
}	t_player_position;

typedef enum e_parse_checklist
{
	FOUND_NO = 0,
	FOUND_SO,
	FOUND_EA,
	FOUND_WE,
	FOUND_C,
	FOUND_F,
	FOUND_MAP,
	READING_MAP = 6,
	SCENE_DATA_FOUND = 6,
	ALL_FOUND = 7,
	CHECKLIST_SIZE = 7
}	t_parse_checklist;

typedef struct s_map
{
	char	*texture_paths[TEXTURE_PATHS + 1];
	int		floor_color[RGB_VALUES];
	int		ceiling_color[RGB_VALUES];
	int		parse_checklist[CHECKLIST_SIZE];
	char	**map;
	int		player[POSITION];
	char	spawn_orientation;
	int		height;
	int		width;
}	t_map;

#endif
