/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 13:16:42 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/09 14:49:00 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGES_H
# define ERROR_MESSAGES_H

//
/*	*	general messages	*	*/
# define MALLOC_FAILED "Malloc failed"
# define EXPECTED_USAGE "Expected usage: ./cub3D [filename].cub"
//
/*	*	mlx error messages	*	*/
# define INIT_MLX "Init mlx failed"
# define WINDOW_MLX "Create window with mlx failed"
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
# define WHITESPACE_ON_MAP "Found forbidden whitespace char, use only ascii 32"

#endif
