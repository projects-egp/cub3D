/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:23:38 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/04/04 20:09:17 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

static void	init_mlx_data(t_mlx *mlx_data, t_map *file_data)
{
	mlx_data->map_data = file_data;
	return ;
}

int	main(int argc, char **argv)
{
	t_mlx	mlx_data;//t_mlx must be defined, is not given by minilibx
	t_map	file_data;
	
	if (argc != 2)
	{
		ft_putendl_error(EXPECTED_USAGE);
		return (1);
	}
	if (!open_file(argv[1], &file_data))
		return (1);
	init_mlx_data(&mlx_data, &file_data);
	clean_up(&mlx_data);
	return (0);
}
