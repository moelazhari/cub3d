/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-khad <yel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:16:21 by mazhari           #+#    #+#             */
/*   Updated: 2022/10/05 14:10:56 by yel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_exit("Error mlx", data, 0);
	data->map.map = malloc(sizeof(char *));
	data->map.map[0] = NULL;
	data->map.row = 0;
	data->map.col = 0;
	data->win.w = 1024;
	data->win.h = 980;
	data->px = 0;
	data->py = 0;
	data->angl = -1;
	data->texture.no.img = NULL;
	data->texture.so.img = NULL;
	data->texture.we.img = NULL;
	data->texture.ea.img = NULL;
	data->f = 0;
	data->c = 0;
	data->move = 0;
	data->strafe = 0;
	data->rotation = 0;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_exit("Error arg", &data, 0);
	init_game(&data);
	pars_file(av[1], &data);
	generate_game(&data);
	mlx_hook(data.win.win, 2, 0, key_handler, &data);
	mlx_hook(data.win.win, 3, 0, key_release, &data);
	mlx_hook(data.win.win, 17, 0, destroy_notify, &data);
	mlx_loop_hook(data.mlx, render_frame, &data);
	mlx_loop(data.mlx);
}
