/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:33:05 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/09 13:21:26 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_MAP_H
# define STRUCT_MAP_H

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
