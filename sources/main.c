/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:23:38 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/05/11 10:02:23 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx_data;
	t_map	file_data;

	if (argc != 2)
	{
		ft_putendl_error(EXPECTED_USAGE);
		return (1);
	}
	if (!open_file(argv[1], &file_data))
		return (1);
	if (!init_mlx_data(&mlx_data, &file_data))
	{
		/*If mlx_new_image() changes to return (0) to close_program(),
		 * remove this scope, because in that case this will be
		 * not necessary*/
		clean_file_data(&file_data);
		return (1);
	}
	run_mlx_loop(&mlx_data);
	return (0);
}
