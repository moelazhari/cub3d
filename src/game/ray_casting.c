/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:23:05 by yel-khad          #+#    #+#             */
/*   Updated: 2022/10/02 17:18:35 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_ray	*ray_casting(t_data *data)
{
	int		x;
	double	ra;

	ra = data->angl + (30 * DEGRE);
	data->ray = malloc(data->win.w * sizeof(t_ray));
	x = 0;
	while (x < data->win.w)
	{
		data->ray[x] = distance(data->px, data->py, ra, data);
		ra -= (60 * DEGRE) / data->win.w;
		x++;
	}
	return (data->ray);
}
