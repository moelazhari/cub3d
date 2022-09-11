/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:16:21 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/11 19:50:05 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void start_game(t_data *data)
{   
	data->mlx = mlx_init();
    data->map.map = NULL;
    data->map.row = 0;
    data->map.col = 0;
    data->player.row = 0;
    data->player.col = 0;
    data->player.view = 0;
    data->no = NULL;
    data->so = NULL;
    data->wo = NULL;
    data->ea = NULL;
    data->f = 0;
    data->c = 0;
}

// static void fill(int *ray)
// {
//     int i = 0;
//     while(i < 2112)
//     {
//         ray[i] = 400;
//         i++;    
//     }
// }


int main(int ac, char **av)
{
    t_data  data;
    
    if (ac != 2)
        ft_exit("Error arg", &data);
    start_game(&data);
    pars_file(av[1], &data);
    generate_game(&data);
    // render_game(ray);
    mlx_loop(data.mlx);
}