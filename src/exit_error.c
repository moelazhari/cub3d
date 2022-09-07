/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:59:05 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/06 18:32:58 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	exit_error(int error, t_data *data)
{
	if (error == 0)
		ft_putendl_fd("Argument Error", 2);
    if (error == 1)
		ft_putendl_fd("File Error", 2);
    if (data->map)
        free(data->map);
	exit(1);
}