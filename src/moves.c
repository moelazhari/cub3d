/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-khad <yel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:31:57 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/23 17:10:51 by yel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int render_frame(t_data *data)
{
	data->angl += (2 * DEGRE) * data->rotation;
	if (data->angl > 2 * PI)
		data->angl -= 2 * PI;
	else if (data->angl < 0)
		data->angl += 2 * PI;
    if (distance(data->px, data->py, data->angl - (PI * (data->move == -1)), data).dist > 32)
    {
        data->px += cos(data->angl) * 10 * data->move;
        data->py -= sin(data->angl) * 10 * data->move;
    }
   	if (distance(data->px, data->py, data->angl + (PI /2) * (data->strafe), data).dist > 32)
    {
		// printf("%f\ncos==%f\ndata->strafe====%d\n",data->angl, cos((PI/2) +data->angl), data->strafe);
        data->px += cos((PI / 2) + data->angl) * 10 * data->strafe;
	    data->py -= sin((PI / 2) + data->angl) * 10 * data->strafe;
    }
	render_game(data);
    return(0);
}

int	key_handler(int key, t_data *data)
{
	if (key == KEY_RIGHT)
		data->rotation = -1;
	if (key == KEY_LEFT)
		data->rotation = 1;
	if (key == KEY_W)
		data->move = 1;
	if (key == KEY_S)
		data->move = -1;
	if (key == KEY_A)
		data->strafe = 1;
	if (key == KEY_D)
		data->strafe = -1;
	render_frame(data);
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == KEY_W || key == KEY_S)
		data->move = 0;
	if (key == KEY_A || key == KEY_D)
		data->strafe = 0;
	if (key == KEY_LEFT || key == KEY_RIGHT)
		data->rotation = 0;
	return (1);
}