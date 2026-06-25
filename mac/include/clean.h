/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 15:05:28 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/09 15:10:34 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_H
# define CLEAN_H

void	clean_up(t_mlx *mlx_data);
void	clean_file_data(t_map *file_data);
void	destroy_mlx_requested(t_mlx *mlx);

#endif
