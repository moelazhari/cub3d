/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:48:29 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/15 19:03:40 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color, t_data *data)
{
	char	*dst;

	if (y < )
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
		if (data->angl < 0)
			data->angl += 2*PI;
		else if (data->angl > 2*PI)
			data->angl -= 2*PI;
		if (key == 123)
		{
			data->dx = cos(data->angl) * 5;
			data->dy = sin(data->angl) * 5;
		}
		else 
		{
			data->dx = cos(data->angl) * 5;
			data->dy = sin(data->angl) * 5;
		}
	}
	else if (key == 125 || key == 126)
	{
		if (key == 126)
		{
			if (distance(data->px, data->py, data->angl, data) > 2)
			{
			data->px += data->dx;
			data->py += data->dy;
			}
		}
		else
		{
			if (distance(data->px, data->py, data->angl-PI, data) > 2 )
			{
			data->py -= data->dy;
			data->px -= data->dx;
			}
		}
	}
	// else if (key == 53)
	// 	ft_exit(key, d`ata);
	data->img.img = mlx_new_image(data->mlx, data->win.w, data->win.h);
	render_game(data);
	return (0);
}

void render_game(t_data *data)
{
    int x = 0;
    int y;
	data->ray = draw_walls(data);
	y = 0;
	// while (y<60)
	// 	printf("%d\n",data->ray[y++]);
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


