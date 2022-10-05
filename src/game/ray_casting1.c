/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-khad <yel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:02:21 by mazhari           #+#    #+#             */
/*   Updated: 2022/10/05 15:52:09 by yel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	find_wall_horizontal(int eof, double xo, double yo, t_data *data)
{
	int		mx;
	int		my;

	while (eof < data->map.row)
	{
		mx = (int)(data->ray->hx) / CUB_SIZE;
		my = (int)(data->ray->hy) / CUB_SIZE;
		if (mx >= 0 && mx < data->map.col && my < data->map.row \
		&& my >= 0 && data->map.map[my][mx] == '1')
			eof = data->map.row;
		else
		{
			data->ray->hx += xo;
			data->ray->hy += yo;
			eof++;
		}
	}
}

static double	horizontal(int px, int py, double ra, t_data *data)
{
	double	disth;
	double	xo;
	double	yo;
	int		eof;

	eof = 0;
	if (sin(ra) > 0)
	{
		data->ray->hy = ((py / CUB_SIZE) * CUB_SIZE) - 0.000001;
		data->ray->hx = (py - data->ray->hy) / tan(ra) + px;
	}
	else if (sin(ra) < 0)
	{
		data->ray->hy = ((py / CUB_SIZE) * CUB_SIZE) + CUB_SIZE;
		data->ray->hx = (py - data->ray->hy) / tan(ra) + px;
	}
	else
		eof = data->map.row;
	yo = CUB_SIZE * (1 - (2 * (sin(ra) > 0)));
	xo = -yo / tan(ra);
	find_wall_horizontal(eof, xo, yo, data);
	disth = sqrt(((data->ray->hx - px) * (data->ray->hx - px)) \
	+ ((data->ray->hy - py) * (data->ray->hy - py)));
	return (disth);
}

static void	find_wall_vertical(int eof, double xo, double yo, t_data *data)
{		
	int		mx;
	int		my;

	while (eof < data->map.col)
	{
		mx = (int)(data->ray->vx) / CUB_SIZE;
		my = (int)(data->ray->vy) / CUB_SIZE;
		if (mx >= 0 && mx < data->map.col && my < data->map.row && \
		my >= 0 && data->map.map[my][mx] == '1')
			eof = data->map.col;
		else
		{
			data->ray->vx += xo;
			data->ray->vy += yo;
			eof++;
		}
	}
}

static double	vertical(int px, int py, double ra, t_data *data)
{
	double	distv;
	double	xo;
	double	yo;
	int		eof;

	eof = 0;
	if (cos(ra) > 0)
	{
		data->ray->vx = ((px / CUB_SIZE) * CUB_SIZE) + CUB_SIZE;
		data->ray->vy = (px - data->ray->vx) * tan(ra) + py;
	}
	else if (cos(ra) < 0)
	{
		data->ray->vx = ((px / CUB_SIZE) * CUB_SIZE) - 0.000001;
		data->ray->vy = (px - data->ray->vx) * tan(ra) + py;
	}
	else
		eof = data->map.col;
	xo = CUB_SIZE * (1 - 2 * (cos(ra) < 0));
	yo = -xo * tan(ra);
	find_wall_vertical(eof, xo, yo, data);
	distv = sqrt(((data->ray->vx - px) * (data->ray->vx - px)) \
	+ ((data->ray->vy - py) * (data->ray->vy - py)));
	return (distv);
}

t_ray	distance(int px, int py, double ra, t_data *data)
{
	double	disth;
	double	distv;
	t_ray	ret;

	disth = horizontal(px, py, ra, data);
	distv = vertical(px, py, ra, data);
	if (distv >= disth)
	{
		ret.dist = disth;
		if (disth != 0)
			ret.wall_h = data->win.h / \
				(disth * fabs(cos(ra - data->angl)) / CUB_SIZE);
		ret.view = ('N' * (sin(ra) > 0)) + ('S' * (sin(ra) < 0));
		ret.offset_x = (int)data->ray->hx % CUB_SIZE;
		return (ret);
	}
	ret.dist = distv;
	if (distv != 0)
		ret.wall_h = data->win.h / (distv * fabs(cos(ra - data->angl)) \
		/ CUB_SIZE);
	ret.view = ('W' * (cos(ra) > 0)) + ('E' * (cos(ra) < 0));
	ret.offset_x = (int)data->ray->vy % CUB_SIZE;
	return (ret);
}
