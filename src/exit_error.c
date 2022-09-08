/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:59:05 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/07 19:22:30 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_exit(char *error_msg, t_data *data)
{
	(void)data;
	if (error_msg)
		ft_putendl_fd(error_msg, 2);
    // if (data->map->map)
    // 	free(data->map);
	exit(1);
}