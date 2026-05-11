/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:41:33 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/11 11:21:35 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

uint_32	get_color_value(int *decimal_value)
{
	uint_32	result;

	result = decimal_value[RED] << 16 | decimal_value[GREEN] << 8
		| decimal_value[BLUE];
	printf("Result is %d", result);//debug
	return (result);
}
