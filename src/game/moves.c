/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:31:57 by mazhari           #+#    #+#             */
/*   Updated: 2022/10/05 13:28:32 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	render_frame(t_data *data)
{
	data->angl += (2 * DEGRE) * data->rotation;
	if (data->angl > 2 * PI)
		data->angl -= 2 * PI;
	else if (data->angl < 0)
		data->angl += 2 * PI;
	if (distance(data->px, data->py, data->angl \
	- (PI * (data->move == -1)), data).dist > 20)
	{
		data->px += round(cos(data->angl) * 10 * data->move);
		data->py -= round(sin(data->angl) * 10 * data->move);
	}
	if (distance(data->px, data->py, data->angl \
	+ (PI / 2) * (data->strafe), data).dist > 20)
	{
		data->px += round(cos((PI / 2) + data->angl) * 10 * data->strafe);
		data->py -= round(sin((PI / 2) + data->angl) * 10 * data->strafe);
	}
	render_game(data);
	return (0);
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
	if (key == KEY_ESC)
		destroy_notify(data);
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
