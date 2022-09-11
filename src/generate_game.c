/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:48:29 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/11 20:08:49 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// static void my_mlx_pixel_put(t_img *img, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }


// void render_game(t_data *data)
// {    
//     // int     ray[data->win.w];
//     // int c;
//     // int f;
//     // int i;
//     // int j;
    
//     // fill(&ray);
//     // i = 0;
//     // j = 0;
//     // while (i < data->win.w)
//     // {
//     //     j = 0;
//     //     c = ((data->win.h) - ray[i]) / 2;
//     //     while (j < data->win.h)
//     //     {
//     //         if (j < c)
                

            
//     //     }
//     //     /* code */
//     // }
    
//     int x = 0;
//     while (x < data->win.w)
//     {
//         int y = 0;
//         while (y < data->win.h)
//         {
// 	        my_mlx_pixel_put(data, x, y, 0x00FF0000);
//             y++;
//         }
//         x++;
//     }
//     mlx_put_image_to_window(data->mlx, data->win.win, data->img.img, 0, 0);
// }

static void generate_win(t_data *data)
{
    data->win.w = WIDTH * data->map.col;
    data->win.h = HEIGHT * data->map.row;
    data->win.win = mlx_new_window(&data->mlx, data->win.w,\
	   data->win.h, "cub3d");
    data->img.img = mlx_new_image(data->mlx, data->win.w, data->win.h);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,\
    &data->img.line_length, &data->img.endian);
}

void    generate_game(t_data *data)
{
    generate_win(data);
    render_game(data);
}


