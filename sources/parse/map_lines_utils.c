/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lines_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:29:37 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/05 14:38:45 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	add_new_line(char *line, t_list **map_lines_list)
{
	t_list	*new;

	new = NULL;
	new = ft_lstnew(line);
	if (!new)
	{
		free_full_list_and_contents(map_lines_list);
		return (0);
	}
	ft_lstadd_front(map_lines_list, new);
	return (1);
}
