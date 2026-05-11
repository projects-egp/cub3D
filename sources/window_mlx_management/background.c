/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:41:33 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/11 11:38:48 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

uint32_t	get_color_value(int *decimal_value)
{
	uint32	result;

	result = decimal_value[RED] << 16 | decimal_value[GREEN] << 8
		| decimal_value[BLUE];
	return (result);
}
