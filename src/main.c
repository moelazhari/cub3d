/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:16:21 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/09 19:30:54 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void start_game(t_data *data)
{   
    data->mlx= mlx_init();
    data->map.map = NULL;
    data->map.row = 0;
    data->map.row = 0;
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

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    
    t_data  data;
    if (ac != 2)
        ft_exit("Error arg", &data);
    start_game(&data);
    pars_file(av[1], &data);
}