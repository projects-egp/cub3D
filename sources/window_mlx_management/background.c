/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:41:33 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/11 11:13:23 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

uint_32	get_color_value(int *decimal_values)
{
	int	result;
	int	bit_operator;
	int	i;

	bit_operator = 16;
	i = 0;
	while (i < RGB_VALUES)
	{
		//conversion
		++i;
		bit_operator /= 8;
	}
}
