/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-khad <yel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:23:05 by yel-khad          #+#    #+#             */
/*   Updated: 2022/09/23 16:47:54 by yel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_ray	distance(int px, int py, double angle, t_data *data)
{
	double 	distH;
	double	distV;
	int		dof, mx, my;
	double 	ra = angle, rx,ry,xo,yo, hx,hy;
	double aTan;
	t_ray	ret;
/////////////////////HORIZONTAL/////////////////////
	dof = 0;
	aTan= 1.0/tan(ra);
	if (sin(ra) > 0.0001)
	{
		ry = ((py / CUB_SIZE)* CUB_SIZE) - 0.000001;
		rx = (py - ry)*aTan + px;
		yo = -CUB_SIZE;
		xo = -yo*aTan;
	}
	else if (sin(ra) < -0.0001)
	{
		ry = ((py / CUB_SIZE)* CUB_SIZE) + CUB_SIZE;
		rx = (py - ry)*aTan + px;
		yo = CUB_SIZE;
		xo = -yo*aTan;
	}
	else
	{
		dof = data->map.row;
	}
	while (dof < data->map.row)
	{
		mx = (int)(rx) / CUB_SIZE;
		my = (int)(ry) / CUB_SIZE;
		if (mx >= 0 && mx < data->map.col && my < data->map.row && my >= 0 && data->map.map[my][mx] == '1')
			dof = data->map.row;
		else
		{
			rx += xo;
			ry += yo;
			dof++;
		}
	}
	hx = rx;
	hy = ry;
/////////////////////VERTICAL//////////////////
	dof = 0;
	aTan= tan(ra);
	if (cos(ra) > 0.0001)
	{
		rx = ((px / CUB_SIZE)* CUB_SIZE)  + CUB_SIZE;
		ry = (px - rx)*aTan + py;
		xo = CUB_SIZE;
		yo = -xo*aTan;
	}
	else if (cos(ra) < -0.0001)
	{
		rx = ((px / CUB_SIZE)* CUB_SIZE) - 0.000001;
		ry = (px - rx)*aTan + py;
		xo = -CUB_SIZE;
		yo = -xo*aTan;
	}
	else
	{
		dof = data->map.col;
	}
	while (dof < data->map.col)
	{
		mx = (int)(rx) / CUB_SIZE;
		my = (int)(ry) / CUB_SIZE;
		if (mx >= 0 && mx < data->map.col && my < data->map.row && my >= 0 && data->map.map[my][mx] == '1')
			dof = data->map.col;
		else
		{
			rx += xo;
			ry += yo;
			dof++;
		}
	}
////////////////////////////////////////////////
	distH = sqrt(((hx-px)*(hx-px)) + ((hy-py)*(hy-py)));
	distV = sqrt(((rx-px)*(rx-px)) + ((ry-py)*(ry-py)));
	if (distV >= distH)
	{
		ret.dist = distH;
		if (distH != 0)
			ret.wall_h= data->win.h / ((distH * fabs(cos(ra - data->angl))) / CUB_SIZE);
		ret.view = ('N' * (sin(angle) > 0)) + ('S' * (sin(angle) < 0));
		ret.offset_x = (int)hx % CUB_SIZE;
		return (ret);
	}
	ret.dist = distV;
	if (distV != 0)
		ret.wall_h = data->win.h / ((distV * fabs(cos(ra - data->angl))) / CUB_SIZE);
	ret.view = ('W' * (cos(angle) > 0)) + ('E' * (cos(angle) < 0));
	ret.offset_x = (int)ry % CUB_SIZE;
	return (ret);
}

t_ray	*ray_casting(t_data *data)
{
	t_ray	*ret;
	int		x;
	double	ra = data->angl + (30 * DEGRE);

	ret = malloc(data->win.w  * sizeof(t_ray));
	x = 0;
	while (x < data->win.w)
	{
		ret[x] = distance(data->px, data->py, ra, data);
		ra -= (60 * DEGRE) / data->win.w;
		x++;
	}
	return (ret);
}
