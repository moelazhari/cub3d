/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:48:29 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/16 18:17:04 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color, t_data *data)
{
	char	*dst;

	if ((y >= 0 && y < data->win.h) && (x >= 0 && x < data->win.w) )
	{
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

static void render_game(t_data *data)
{
    int x = 0;
    int y;
	data->ray = draw_walls(data);
	y = 0;

    while (x < data->win.w)
    {
        y = 0;
        while (y < (data->win.h - data->ray[x]) / 2)
	        my_mlx_pixel_put(&(data->img), x, y++, data->c, data);
        while (y < ((data->win.h - data->ray[x]) / 2) + data->ray[x])
	        my_mlx_pixel_put(&(data->img), x, y++, 0x0000FF00, data);
        while(y < data->win.h)
            my_mlx_pixel_put(&(data->img), x, y++, data->f, data);
        x++;
    }
	mlx_put_image_to_window(data->mlx, data->win.win, data->img.img, 0, 0);
	mlx_destroy_image(data->mlx, data->img.img);
}

int	key_handler(int key, t_data *data)
{
	if (key == LEFT || key == RIGHT)
	{
		if (key == RIGHT)
			data->angl += 3 * DEGRE;
		else 
			data->angl -= 3 * DEGRE;
	}
	else if (key == UP || key == DOWN)
	{
		if (key == UP)
		{
			if (distance(data->px, data->py, data->angl, data) > 6)
			{
				data->px += cos(data->angl) * 5;
				data->py -= sin(data->angl) * 5;
			}
		}
		else
		{
			if (distance(data->px, data->py, data->angl, data) > 6)
			{
				data->px -= cos(data->angl) * 5;
				data->py += sin(data->angl) * 5;
			}
		}
	}
	data->img.img = mlx_new_image(data->mlx, data->win.w, data->win.h);
	render_game(data);
	return (0);
}


void	generate_game(t_data *data)
{
	data->win.win = mlx_new_window(data->mlx, data->win.w,\
	data->win.h, "cub3d");
	data->img.img = mlx_new_image(data->mlx, data->win.w, data->win.h);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length,
								&data->img.endian);
	render_game(data);
}
