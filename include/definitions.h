/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:33:05 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/14 17:25:27 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# include "general.h"
//
/*	*	general messages	*	*/
# define MALLOC_FAILED "Malloc failed"
# define EXPECTED_USAGE "Expected usage: ./cub3D [filename].cub"
//
/*	*	parse error messages	*	*/
# define SCENE_DATA_ERROR "Expected scene data: identifier + information"
# define IDENTIFIER_ERROR "Found wrong identifier for scene data"
# define FILE_FORMAT_ERROR "Expected file format: <name>.cub"
# define FILE_NAMED_DOTCUB "Good file format, but file has no name"
# define RGB_VALUES_ERROR "RGB values expected as three integers, format: 0,0,0"
# define SAME_COLOR_C_F "Ceiling and floor has exactly same color"
# define COLOR_VALUE_LIMITS "RGB values must be integers between 0 and 255"
# define UNCOMPLETE_DATA "Uncomplete file. It must have scene data and a map"
# define TWO_PLAYER_POSITIONS "Map must have just one start position"
# define WRONG_CHAR_FOUND "Found wrong char inside map content"
# define MAP_NOT_CLOSED "Map is not properly closed by walls"
# define MAP_WITHOUT_SPAWN "Map has no spawn position for player"
# define NEW_LINE_INSIDE_MAP "Found new line inside map content"
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

typedef enum e_pplayer_position
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
