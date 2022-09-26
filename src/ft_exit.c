/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:59:05 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/25 14:53:37 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_freearr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

int	destroy_notify(t_data *data)
{
	ft_exit("\n|!|!| quit successfully |!|!|\n", data);
	return (0);
}

void	ft_exit(char *error_msg, t_data *data)
{
	if (error_msg)
		ft_putendl_fd(error_msg, 2);
	if (data->map.map)
		ft_freearr(data->map.map);
	if (data->texture.no.img)
		mlx_destroy_image(data->mlx, data->texture.no.img);
	if (data->texture.so.img)
		mlx_destroy_image(data->mlx, data->texture.so.img);
	if (data->texture.we.img)
		mlx_destroy_image(data->mlx, data->texture.we.img);
	if (data->texture.ea.img)
		mlx_destroy_image(data->mlx, data->texture.ea.img);
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	exit(0);
}
