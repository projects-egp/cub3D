/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enrgil-p <enrgil-p@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:11:35 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/03/19 17:35:57 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	read_data(char *cub_file_path, t_mlx *data, int fd)
{
	char	*line_read;

	while (1)
	{
		line_read = safe_call_to_get_next_line(fd);
	}
	//Read information
	//Read map
}
