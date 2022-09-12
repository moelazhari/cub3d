/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:48:29 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/12 16:01:23 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void render_game(t_data *data)
{
    int     ray[data->win.w];
    
	data->img.img = mlx_new_image(data->mlx, data->win.w, data->win.h);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length,
								&data->img.endian);
    
    int x = 0;
    int i = 0;
    while(x < data->win.w)
    {
        if (x < 200)
            ray[x] = 600 - x;
        else
            ray[x] = 400;
        if (x > data->win.w - 400)
        {
            ray[x] = 400 + i;
            i++;
        }
        x++;    
    }
    x = 0;
    int y;
    while (x < data->win.w)
    {
        y = 0;
        while (y < (data->win.h - ray[x]) / 2)
	        my_mlx_pixel_put(&(data->img), x, y++, data->c);
        while (y < ((data->win.h - ray[x]) / 2 + ray[x]))
	        my_mlx_pixel_put(&(data->img), x, y++, 0x0000FF00);
        while(y < data->win.h)
            my_mlx_pixel_put(&(data->img), x, y++, data->f);
        x++;
    }
	mlx_put_image_to_window(data->mlx, data->win.win, data->img.img, 0, 0);
}

static void generate_win(t_data *data)
{
    data->win.w = WIDTH * data->map.col;
    data->win.h = HEIGHT * data->map.row;
    data->win.win = mlx_new_window(data->mlx, data->win.w,\
	   data->win.h, "cub3d");
}

void    generate_game(t_data *data)
{
    generate_win(data);
    render_game(data);
}


