/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:10:20 by enrgil-p          #+#    #+#             */
/*   Updated: 2025/01/17 19:10:29 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"

static char	*get_endptr(const char *str)
{
	const char	*expected_null;
	int i;
	/*ADD HERE COUNTER. COUNT IN ISDIGIT LOOP, IF IT IT'S BIGGER THAN 10,
	 * SHOULD STOP BECAUSE THERE'S A WRONG INPUT ARGUMENT*/

	expected_null = str;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i++]))
		expected_null = &str[i];
	return ((char *)expected_null);
}

long	ft_strtol_10(const char *source_str, char **endptr)
{
	char	*aux;
	size_t	aux_len;
	long	result;
	
	if (!ft_strchr_digit(source_str))
	{
		*endptr = (char *)source_str;
		return (0);
	}
	*endptr = get_endptr(source_str);
	if (!endptr)
		result = ft_atol(source_str);
	else
	{
		aux_len = ft_strlen(source_str) - ft_strlen(*endptr);
		aux = ft_substr(source_str, 0, aux_len);
		if (!aux)
			return (0);
		result = ft_atol(aux);
		free(aux);
	}
	return (result);
}
