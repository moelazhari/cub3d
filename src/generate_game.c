/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-khad <yel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:48:29 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/12 20:08:29 by yel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int	key_handler(int key, t_data *data)
{
	double	rx;
	double	ry;

	if (key == 123 || key == 124)
	{
		data->angl += (1 - 2 * (key == 123)) * 0.1;
		if (key == 123)
		{
			if (data->angl < 0)
				data->angl += 2*3.14;
			data->dx = cos(data->angl) * 5;
			data->dy = sin(data->angl) * 5;
		}
		else 
		{
			if (data->angl > 2*3.14)
				data->angl -= 2*3.14;
			data->dx = cos(data->angl) * 5;
			data->dy = sin(data->angl) * 5;
		}
	}
	else if (key == 125 || key == 126)
	{
		if (key == 126)
		{
			if (data->map.map[(int)(data->py + data->dy ) / PIXELS][(int)(data->px + data->dx ) / PIXELS] == '0'\
				&& data->map.map[(int)(data->py + data->dy ) / PIXELS][(int)(data->px + data->dx ) / PIXELS] == '0')
			{
			// exit(1);
			data->px += data->dx;
			data->py += data->dy;
			}
		}
		else
		{
			// if (data->map[(int)(data->py - data->dy - 20) / (LIN_N * 10)][(int)(data->px - data->dx - 20) / (COL_N * 10)] == '0')
			// {
			if (data->map.map[(int)(data->py - data->dy ) / PIXELS][(int)(data->px - data->dx ) / PIXELS] == '0'\
				&& data->map.map[(int)(data->py - data->dy ) / PIXELS][(int)(data->px - data->dx ) / PIXELS] == '0')
			{
			// exit(1);
			data->py -= data->dy;
			data->px -= data->dx;
			}
		}
	}
	// else if (key == 53)
	// 	ft_exit(key, data);
	data->img.img = mlx_new_image(data->mlx, WIDTH * data->map.col, HEIGHT * data->map.row);
	render_game(data);
	return (0);
}

void render_game(t_data *data)
{

    
    int x = 0;
    // int i = 0;
    // while(x < data->win.w)
    // {
    //     if (x < 200)
    //         ray[x] = 600 - x;
    //     else
    //         ray[x] = 400;
    //     if (x > data->win.w - 400)
    //     {
    //         ray[x] = 400 + i;
    //         i++;
    //     }
    //     x++;    
    // }
    x = 0;
    int y;
    while (x < data->win.w)
    {
        y = 0;
        while (y < (data->win.h - data->ray[x]) / 2)
	        my_mlx_pixel_put(&(data->img), x, y++, data->c);
        while (y < ((data->win.h - data->ray[x]) / 2 + data->ray[x]))
	        my_mlx_pixel_put(&(data->img), x, y++, 0x0000FF00);
        while(y < data->win.h)
            my_mlx_pixel_put(&(data->img), x, y++, data->f);
        x++;
    }
	mlx_put_image_to_window(data->mlx, data->win.win, data->img.img, 0, 0);
}

static void generate_win(t_data *data)
{
    data->win.w = 32 * data->map.col;
    data->win.h = HEIGHT * data->map.row;
    data->win.win = mlx_new_window(data->mlx, data->win.w,\
	   data->win.h, "cub3d");
	data->img.img = mlx_new_image(data->mlx, data->win.w, data->win.h);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length,
								&data->img.endian);
}

void    generate_game(t_data *data)
{
	data->ray = draw_image_mandelbrot(data);
    generate_win(data);
    render_game(data);
}


