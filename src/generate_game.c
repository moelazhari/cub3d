/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-khad <yel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:48:29 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/19 19:51:26 by yel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color, t_data *data)
{
	char	*dst;

	if ((y >= 0 && y < data->win.h) && (x >= 0 && x < data->win.w) )
	{
		dst = (char *)img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}


static void render_game(t_data *data)
{
    int x = 0;
    int y;
	double rap;
	data->ray = ray_casting(data);
	y = 0;
	int tmp;
	
    while (x < data->win.w)
    {
        y = 0;
        while (y < data->win.h / 2)
	        my_mlx_pixel_put(&(data->img), x, y++, data->c, data);
        while(y < data->win.h)
            my_mlx_pixel_put(&(data->img), x, y++, data->f, data);
        x++;
    }
	x = 0;
    while (x < data->win.w)
	{
		rap =  CUB_SIZE / data->ray[x].wall_h;
		y = (data->win.h - data->ray[x].wall_h) / 2;
		while (y < (data->win.h / 2) - (data->ray[x].wall_h / 2) + data->ray[x].wall_h)
		{
			tmp = (y - ((data->win.h - data->ray[x].wall_h) / 2)) * rap;			
	    	my_mlx_pixel_put(&(data->img), x, y, data->texture.no.addr[(tmp * (data->texture.no.line_length / 4)) + data->ray[x].offset_x], data);
			// printf("%d\n", (y % CUB_SIZE));
			// if (data->texture.view == 'E')
	       	//  	my_mlx_pixel_put(&(data->img), x, y, data->texture.ea.addr[((y % CUB_SIZE) * (data->texture.ea.line_length) / 4) + data->texture.offset_x[x]], data);
			// if (data->texture.view == 'W')
	       	//  	my_mlx_pixel_put(&(data->img), x, y, data->texture.we.addr[((y % CUB_SIZE) * (data->texture.we.line_length) / 4) + data->texture.offset_x[x]], data);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win.win, data->img.img, 0, 0);
	mlx_destroy_image(data->mlx, data->img.img);
}

void	moveing_up_down(int key, t_data *data)
{
	if (key == KEY_UP || key == KEY_W)
	{
		if ((data->win.h * CUB_SIZE) / distance(data->px, data->py, data->angl, data).wall_h > 10)
		{
			data->px += cos(data->angl) * 10;
			data->py -= sin(data->angl) * 10;
		}
	}
	else
	{
		if ((data->win.h * CUB_SIZE) / distance(data->px, data->py, data->angl - PI, data).wall_h > 10)
		{
			data->px -= cos(data->angl) * 10;
			data->py += sin(data->angl) * 10;
		}
	}
}

int	key_handler(int key, t_data *data)
{
	if (key == KEY_LEFT || key == KEY_RIGHT)
	{
		if (key == KEY_RIGHT)
			data->angl += 5 * DEGRE;
		else 
			data->angl -= 5 * DEGRE;
	}
	if (key == KEY_UP || key == KEY_DOWN || key == KEY_W || key == KEY_S)
		moveing_up_down(key, data);
	else if (key == KEY_A)
	{
		printf("%f\n", (data->win.h * CUB_SIZE) / distance(data->px, data->py, data->angl - (PI /2), data).wall_h);
		if ((data->win.h * CUB_SIZE) / distance(data->px, data->py, data->angl - (PI /2), data).wall_h > 10)
		{
			data->px += cos((PI / 2) - data->angl) * 10;
			data->py += sin((PI / 2) - data->angl) * 10;
		}
	}
	else if (key == KEY_D)
	{
		data->px -= sin(data->angl) * 10;
		data->py -= cos(data->angl) * 10;
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
	data->img.addr = (int *)mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length,
								&data->img.endian);
	render_game(data);
}
