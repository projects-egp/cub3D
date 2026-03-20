/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:41:10 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/03/20 18:44:15 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "general.h"

int	open_file(char *cub_file_path, t_mlx *data);
int	read_data(t_mlx *data, int fd);
int	add_scene_data(char *line, t_mlx *data);
int	is_empty_line(char *line, t_mlx *data);

#endif
