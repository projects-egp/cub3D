/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:23:38 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/03/22 20:32:11 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx_data;//t_mlx must be defined, is not given by minilibx
	
	if (argc != 2)
	{
		ft_putendl_error("Error\nExpected usage: ./cub3D [filename].cub");
		return (1);
	}
	if (!open_file(argv[1], &mlx_data))
		return (1);
	return (0);
}
