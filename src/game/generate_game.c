/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:48:29 by mazhari           #+#    #+#             */
/*   Updated: 2022/10/02 16:29:21 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	*dst;

	dst = &img->addr[y * (img->line_length / 4) + x];
	*dst = color;
}

void	put_texture(int x, int y, int offset_y, t_data *data)
{
	int	coller;

	offset_y *= (data->texture.no.line_length / 4);
	if (data->ray[x].view == 'N')
	{
		coller = data->texture.no.addr[offset_y + data->ray[x].offset_x];
		my_mlx_pixel_put(&(data->img), x, y, coller);
	}
	else if (data->ray[x].view == 'S')
	{
		coller = data->texture.so.addr[offset_y + data->ray[x].offset_x];
		my_mlx_pixel_put(&(data->img), x, y, coller);
	}
	else if (data->ray[x].view == 'W')
	{
		coller = data->texture.we.addr[offset_y + data->ray[x].offset_x];
		my_mlx_pixel_put(&(data->img), x, y, coller);
	}
	else
	{
		coller = data->texture.ea.addr[offset_y + data->ray[x].offset_x];
		my_mlx_pixel_put(&(data->img), x, y, coller);
	}
}

void	draw_walls(t_data *data)
{
	int		x;
	int		y;
	int		offset_y;
	double	rap;

	x = 0;
	while (x < data->win.w)
	{
		rap = CUB_SIZE / data->ray[x].wall_h;
		y = (data->win.h - data->ray[x].wall_h) / 2;
		y *= (y > 0);
		while (y < (data->ray[x].wall_h + data->win.h) / 2 && y < data->win.h)
		{
			offset_y = (y - ((data->win.h - data->ray[x].wall_h) / 2)) * rap;
			put_texture(x, y, offset_y, data);
			y++;
		}
		x++;
	}
}

void	render_game(t_data *data)
{
	int	x;
	int	y;

	mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, data->win.w, data->win.h);
	data->img.addr = (int *)mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_length, \
	&data->img.endian);
	data->ray = ray_casting(data);
	x = 0;
	draw_walls(data);
	while (x < data->win.w)
	{
		y = 0;
		while (y < (data->win.h - data->ray[x].wall_h) / 2)
			my_mlx_pixel_put(&(data->img), x, y++, data->c);
		y = (data->win.h + data->ray[x].wall_h) / 2;
		if (y > 0 && y < data->win.h)
			while (y < data->win.h)
				my_mlx_pixel_put(&(data->img), x, y++, data->f);
		x++;
	}
	free(data->ray);
	mlx_put_image_to_window(data->mlx, data->win.win, data->img.img, 0, 0);
}

void	generate_game(t_data *data)
{
	data->win.win = mlx_new_window(data->mlx, data->win.w, \
	data->win.h, "cub3d");
	data->img.img = mlx_new_image(data->mlx, data->win.w, data->win.h);
	data->img.addr = (int *)mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_length, \
	&data->img.endian);
	render_game(data);
}
