/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-khad <yel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:24:04 by yel-khad          #+#    #+#             */
/*   Updated: 2022/09/13 17:34:54 by yel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fractol.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// static void	zoom_inorout(t_data *data, double sx, double sy, char c)
// {
// 	if (c == 'i')
// 	{
// 		data->ref->x_min = ((data->ref->x_min - sx) / 1.6) + sx;
// 		data->ref->x_max = ((data->ref->x_max - sx) / 1.6) + sx;
// 		data->ref->y_min = ((data->ref->y_min - sy) / 1.6) + sy;
// 		data->ref->y_max = ((data->ref->y_max - sy) / 1.6) + sy;
// 	}
// 	else
// 	{
// 		data->ref->x_min = ((data->ref->x_min - sx) * 1.6) + sx;
// 		data->ref->x_max = ((data->ref->x_max - sx) * 1.6) + sx;
// 		data->ref->y_min = ((data->ref->y_min - sy) * 1.6) + sy;
// 		data->ref->y_max = ((data->ref->y_max - sy) * 1.6) + sy;
// 	}
// }

// int	zoom(int key, int x, int y, t_data *data)
// {
// 	double	sx;
// 	double	sy;

// 	sx = (x * (data->ref->x_max - data->ref->x_min) / SIZE) + data->ref->x_min;
// 	sy = (y * (data->ref->y_max - data->ref->y_min) / SIZE) + data->ref->y_min;
// 	if (key == 5)
// 		zoom_inorout(data, sx, sy, 'i');
// 	else if (key == 4)
// 		zoom_inorout(data, sx, sy, 'o');
// 	data->iter += (1 - 2 * (key == 4)) * 20;
// 	data->img = mlx_new_image(data->mlx, SIZE, SIZE);
// 	if (data->x == 'm')
// 		draw_image_mandelbrot(data);
// 	else if (data->x == 'j')
// 		draw_image_julia(data);
// 	return (0);
// }

// int	exit_(int key, t_data *data)
// {
// 	if (key == 53)
// 	{
// 		mlx_destroy_window(data->mlx, data->win);
// 		free(data->ref);
// 	}
// 	exit(1);
// 	return (0);
// }

// int	key_handler(int key, t_data *data)
// {
// 	double	rx;
// 	double	ry;

// 	rx = data->ref->x_max - data->ref->x_min;
// 	ry = data->ref->y_max - data->ref->y_min;
// 	if (key == 123 || key == 124)
// 	{
// 		data->angl += (1 - 2 * (key == 123)) * 0.1;
// 		if (key == 123)
// 		{
// 			if (data->angl < 0)
// 				data->angl += 2*3.14;
// 			data->dx = cos(data->angl) * 5;
// 			data->dy = sin(data->angl) * 5;
// 		}
// 		else 
// 		{
// 			if (data->angl > 2*3.14)
// 				data->angl -= 2*3.14;
// 			data->dx = cos(data->angl) * 5;
// 			data->dy = sin(data->angl) * 5;
// 		}
// 	}
// 	else if (key == 125 || key == 126)
// 	{
// 		if (key == 126)
// 		{
// 			if (data->map[(int)(data->py + data->dy - 10) / PIXELS][(int)(data->px + data->dx - 10) / PIXELS] == '0'\
// 				&& data->map[(int)(data->py + data->dy + 10) / PIXELS][(int)(data->px + data->dx + 10) / PIXELS] == '0')
// 			{
// 			data->px += data->dx;
// 			data->py += data->dy;
// 			}
// 		}
// 		else
// 		{
// 			// if (data->map[(int)(data->py - data->dy - 20) / (LIN_N * 10)][(int)(data->px - data->dx - 20) / (COL_N * 10)] == '0')
// 			// {
// 			if (data->map[(int)(data->py - data->dy - 10) / PIXELS][(int)(data->px - data->dx - 10) / PIXELS] == '0'\
// 				&& data->map[(int)(data->py - data->dy + 10) / PIXELS][(int)(data->px - data->dx + 10) / PIXELS] == '0')
// 			{
// 			data->py -= data->dy;
// 			data->px -= data->dx;
// 			}
// 		}
// 	}
// 	else if (key == 53)
// 		exit_(key, data);
// 	data->img = mlx_new_image(data->mlx, WIDTH, HIGHT);
// 	if (data->x == 'm')
// 		draw_image_mandelbrot(data);
// 	else if (data->x == 'j')
// 		draw_image_julia(data);
// 	return (0);
// }
