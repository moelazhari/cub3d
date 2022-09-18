/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:26:16 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/18 14:41:22 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
    int     w;
    int     h;
	t_data	img;
	t_data	t;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(mlx, 32, 32);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    t.img = mlx_xpm_file_to_image(mlx, "./texture/no.xpm", &w, &h);
    
   	int *i = (int *)mlx_get_data_addr(t.img,
            &t.bits_per_pixel, &t.line_length, &t.endian);
		
	int coller;

    int x = 0;
	int y;
    while (x < 32)
    {
        y = 0;
        while (y < 32)
        {
            
			coller = i[((t.line_length * y) / 4)  + x];
	        my_mlx_pixel_put(&img, x, y, coller);
            y++;
        }
        x++;
    }
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
//     int x = 0;
// 	int y;
//     while (x < 1920)
//     {
//         y = 0;
//         while (y < 1080)
//         {
// 	        my_mlx_pixel_put(&img, x, y, 0x00FF0000);
//             y++;
//         }
//         x++;
//     }
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }