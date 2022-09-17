/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:16:21 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/17 19:12:14 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void init_game(t_data *data)
{   
	data->mlx = mlx_init();
    data->map.map = NULL;
    data->map.row = 0;
    data->map.col = 0;
    data->win.w = 2048;
    data->win.h = 1024;
    data->px = 0;
    data->py = 0;
	data->angl = -1;
    data->texture.no = NULL;
    data->texture.so = NULL;
    data->texture.wo = NULL;
    data->texture.ea = NULL;
    data->f = 0;
    data->c = 0;
}

int main(int ac, char **av)
{
    (void)av;
    t_data  data;
    
    if (ac != 2)
        ft_exit("Error arg", &data);
    init_game(&data);
    pars_file(av[1], &data);
    generate_game(&data);
    mlx_hook(data.win.win, 2, 2L << 0, key_handler, &data);
	mlx_hook(data.win.win, 17, 0, 0, &data);
	mlx_loop(data.mlx);
}