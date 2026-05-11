/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:08:46 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/11 10:13:17 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	key_pressed(int key, t_mlx *mlx)
{
	if (key == ESC)
		close_program(mlx, SUCCESS_CLOSE);
	return (0);
}
