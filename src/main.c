/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:16:21 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/15 18:56:58 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void start_game(t_data *data)
{   
	data->mlx = mlx_init();
    data->map.map = NULL;
    data->map.row = 0;
    data->map.col = 0;
    data->px = 0;
    data->py = 0;
	data->angl = PI / 2;
    data->view = 0;
    data->no = NULL;
    data->so = NULL;
    data->wo = NULL;
    data->ea = NULL;
    data->f = 0;
    data->c = 0;
}


int main(int ac, char **av)
{
    (void)av;
    t_data  data;
    
    if (ac != 2)
        ft_exit("Error arg", &data);
    start_game(&data);
    pars_file(av[1], &data);
	data.win.w = 1080;
    data.win.h = 840;
    // printf("%d\n", );
    data.win.win = mlx_new_window(data.mlx, data.win.w,\
	data.win.h, "cub3d");
	data.img.img = mlx_new_image(data.mlx, data.win.w, data.win.h);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length,
								&data.img.endian);
	render_game(&data);
	mlx_key_hook(data.win.win, key_handler, &data);
	mlx_hook(data.win.win, 17, 0, 0, &data);
	mlx_loop(data.mlx);
	
}