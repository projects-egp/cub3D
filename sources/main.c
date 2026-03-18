/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:23:38 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/03/18 17:38:51 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	t_mlx	mlx_data;//t_mlx must be defined, is not given by minilibx

	//Parse map
	if (argc == 2)
	{
		if (!open_map(argv[1], &mlx_data)
		//Display window
		return (0);
	}
	return (1);
}
