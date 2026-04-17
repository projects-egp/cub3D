/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:33:05 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/17 15:45:41 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# include "general.h"

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
//
//	scene data: ceiling and floor colors
# define RGB_VALUES_CONVERSION "Cannot convert RGB values, non-digit char found"
# define NOT_THREE_RGB_VALUES "Expected three RGB values for ceiling and floor"
# define COLOR_VALUE_LIMITS "RGB values must be integers between 0 and 255"
//
//	scene_data: map
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

typedef struct s_map
{
	char	*texture_paths[TEXTURE_PATHS + 1];
	int		floor_color[RGB_VALUES];
	int		ceiling_color[RGB_VALUES];
	int		parse_checklist;
	char	**map;
	int		player[POSITION];
	char	spawn_orientation;
	int		height;
	int		width;
}	t_map;

typedef struct s_mlx
{
	t_map	*map_data;
}	t_mlx;

#endif
