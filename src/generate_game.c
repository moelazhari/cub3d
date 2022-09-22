/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:48:29 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/22 16:46:22 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color, t_data *data)
{
	char	*dst;

	(void)data;
	dst = (char *)img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_walls(t_data *data)
{
	int		x;
	int		y;
	int		tmp;
	double	rap;

	x = 0;
	while (x < data->win.w)
	{
		rap =  CUB_SIZE / data->ray[x].wall_h;
		y = (data->win.h - data->ray[x].wall_h) / 2;
		y *= (y > 0);
		while (y < (data->ray[x].wall_h + data->win.h) / 2 && y < data->win.h)
		{
			tmp = (y - ((data->win.h - data->ray[x].wall_h) / 2)) * rap;
			if (data->ray[x].view == 'N')
				my_mlx_pixel_put(&(data->img), x, y, data->texture.no.addr[(tmp * (data->texture.no.line_length / 4)) + data->ray[x].offset_x], data);
			else if (data->ray[x].view == 'S')	
				my_mlx_pixel_put(&(data->img), x, y, data->texture.so.addr[(tmp * (data->texture.so.line_length / 4)) + data->ray[x].offset_x], data);
			else if (data->ray[x].view == 'W')
				my_mlx_pixel_put(&(data->img), x, y, data->texture.we.addr[(tmp * (data->texture.we.line_length / 4)) + data->ray[x].offset_x], data);
			else
				my_mlx_pixel_put(&(data->img), x, y, data->texture.ea.addr[(tmp * (data->texture.ea.line_length / 4)) + data->ray[x].offset_x], data);
			y++;
		}
		x++;
	}
}

void	render_game(t_data *data)
{
    int x;
    int y;

	mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, data->win.w, data->win.h);
	data->img.addr = (int *)mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
	data->ray = ray_casting(data);
	x = 0;
	draw_walls(data);
    while (x < data->win.w)
    {
        y = 0;
        while (y < (data->win.h - data->ray[x].wall_h) / 2)
	        my_mlx_pixel_put(&(data->img), x, y++, data->c, data);
		y = (data->win.h + data->ray[x].wall_h) / 2;
		if (y > 0  && y < data->win.h)
		{
       		while(y < data->win.h)
            	my_mlx_pixel_put(&(data->img), x, y++, data->f, data);
		}
        x++;
    }
	free(data->ray);
	mlx_put_image_to_window(data->mlx, data->win.win, data->img.img, 0, 0);
}

void	generate_game(t_data *data)
{
	data->win.win = mlx_new_window(data->mlx, data->win.w,\
	data->win.h, "cub3d");
	data->img.img = mlx_new_image(data->mlx, data->win.w, data->win.h);
	data->img.addr = (int *)mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length,
								&data->img.endian);
	render_game(data);
}
