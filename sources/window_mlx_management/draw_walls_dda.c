/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_dda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 19:41:59 by enrgil-p          #+#    #+#             */
/*   Updated: 2026/06/05 19:22:46 by enrgil-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"

/*ray_direction_value is a sine or cosine. If it is negative, 
 * x or y values of ray will decrease*/
static double	get_side(double position, double ray_direction_value)
{
	double	side;
	
	side = 0;
	if (ray_direction_value < 0) {
		side = position - floor(position);
		if (side < 0.000000001)
			return (1.0);
	} else {
		side = (floor(position) + 1.0) - position;
		if (side < 0.000000001)
			return (1.0);
	}
	return (side);
}

/*ray_direction_value is a sine or cosine. With same formula
 * we can get hypotenuse h. 
 *
 * h = side / (sin || cos)
 *
 * If (sin || cos) == 0, side / ray_direction_value is 
 * protected to avoid a zero-valued divisor*/
static double	get_step(double position, double ray_direction_value)
{
	double	step_hypotenuse;
	double	side;

	if (ray_direction_value == 0)
		return (1e30); // Valor muy grande para evitar división por cero
	side = get_side(position, ray_direction_value);	
	step_hypotenuse = side / ray_direction_value;
	if (step_hypotenuse < 0)
		step_hypotenuse *= -1;
	return (step_hypotenuse);
}

static double	find_next_square(t_ray *ray, int *side)
{
	double	step_x;
	double	step_y;
	double	result;
	int		temp_side;

	step_x = get_step(ray->head[X_POS], ray->direction[X_POS]);
	step_y = get_step(ray->head[Y_POS], ray->direction[Y_POS]);
	if (step_x > step_y)
	{
		ray->head[X_POS] += ray->direction[X_POS] * step_y;
		ray->head[Y_POS] += ray->direction[Y_POS] * step_y;
		temp_side = 1; // Impacto en eje Y (Norte/Sur)
		result = step_y;
	}
	else
	{
		ray->head[Y_POS] += ray->direction[Y_POS] * step_x;
		ray->head[X_POS] += ray->direction[X_POS] * step_x;
		temp_side = 0; // Impacto en eje X (Este/Oeste)
		result = step_x;
	}
	*side = temp_side;
	return (result);
}

static int	ray_hit_wall(t_ray ray, t_mlx *mlx)
{
	char	**map;
	int	x;
	int	y;

	map = mlx->map_data->map;
	// Usamos un pequeño margen (épsilon) para mirar "dentro" del muro
	x = (int)floor(ray.head[X_POS] + (ray.direction[X_POS] * 0.00001));
	y = (int)floor(ray.head[Y_POS] + (ray.direction[Y_POS] * 0.00001));
	if (y >= 0 && y < mlx->map_data->height && x >= 0 && x < mlx->map_data->width)
	{
		if (map[y][x] == '0' || map[y][x] == mlx->map_data->spawn_orientation)
			return (0);
	}
	return (1);
}

double	throw_ray(double angle, t_mlx *mlx, int *side, double *dx, double *dy)
{
	double	length;
	t_ray	ray_data;

	length = 0;
	*side = 0;
	*dx = cos(angle);
	*dy = sin(angle);
	ray_data.direction[X_POS] = *dx;
	ray_data.direction[Y_POS] = *dy;
	ray_data.head[X_POS] = mlx->map_data->player[X_POS];
	ray_data.head[Y_POS] = mlx->map_data->player[Y_POS];
	while (length < 100) // Límite de seguridad para evitar bucles infinitos
	{
		length += find_next_square(&ray_data, side);
		if (ray_hit_wall(ray_data, mlx))
			break ;
	}
	return (length);
}

static void	draw_vertical_line(t_mlx *mlx, int x, int wall_height, int color)
{
	int	y;
	int	start;
	int	end;

	start = (HEIGHT / 2) - (wall_height / 2);
	end = (HEIGHT / 2) + (wall_height / 2);
	if (start < 0)
		start = 0;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	y = start;
	while (y < end)
	{
		my_pixel_put(&mlx->img, x, y, color);
		y++;
	}
}

static int	get_wall_color(int side, double dx, double dy)
{
	if (side == 1) // Impacto en Eje Y (Paredes Norte o Sur)
	{
		if (dy > 0)
			return (0xFF0000); // Rayo baja: golpea cara NORTE (Rojo)
		return (0xFFFF00);     // Rayo sube: golpea cara SUR (Amarillo)
	}
	else // Impacto en Eje X (Paredes Este u Oeste)
	{
		if (dx > 0)
			return (0x00FF00); // Rayo va derecha: golpea cara OESTE (Verde)
		return (0x0000FF);     // Rayo va izquierda: golpea cara ESTE (Azul)
	}
}

void	render_3d_scene(t_mlx *mlx)
{
	int		x;
	double	ray_angle;
	double	distance;
	double	corrected_dist;
	int		wall_height;
	int		side;
	double	dx;
	double	dy;

	x = 0;
	while (x < WIDTH)
	{
		// Calculamos el ángulo del rayo basado en el FOV
		ray_angle = (mlx->map_data->player_angle - (mlx->map_data->fov_angle / 2))
			+ ((double)x / (double)WIDTH) * mlx->map_data->fov_angle;
		distance = throw_ray(ray_angle, mlx, &side, &dx, &dy);
		// Corrección efecto ojo de pez
		corrected_dist = distance * cos(ray_angle - mlx->map_data->player_angle);
		wall_height = (int)(HEIGHT / (corrected_dist + 0.0001));
		draw_vertical_line(mlx, x, wall_height, get_wall_color(side, dx, dy));
		x++;
	}
}
