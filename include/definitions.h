/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:33:05 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/05 14:18:37 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# include "general.h"
//
/*	*	general messages	*	*/
# define MALLOC_FAILED "Error\nMalloc failed"
# define EXPECTED_USAGE "Error\nExpected usage: ./cub3D [filename].cub"
//
/*	*	parse error messages	*	*/
# define SCENE_DATA_ERROR "Error\nExpected scene data: identifier + information"
# define IDENTIFIER_ERROR "Error\nFound wrong identifier or unexpected element"
# define FILE_FORMAT_ERROR "Error\nExpected file format: <name>.cub"
# define FILE_NAMED_DOTCUB "Error\nGood format, but file has no name"
# define RGB_VALUES_ERROR "Error\nRGB integers expected format: 0,0,0"
# define COLOR_VALUE_LIMITS "Error\nCan't convert to integer between 0 and 255"
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

typedef struct s_map
{
	char	*texture_paths[TEXTURE_PATHS + 1];
	int		floor_color[RGB_VALUES];
	int		ceiling_color[RGB_VALUES];
	int		parse_checklist;
	char	**map;
	int		height;
	int		width;
	int		longest_len_line;
}	t_map;

typedef struct s_mlx
{
	t_map	*map_data;
}	t_mlx;

#endif
