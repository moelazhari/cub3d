/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:23:05 by yel-khad          #+#    #+#             */
/*   Updated: 2022/09/18 16:12:19 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

float	distance(int px, int py, float angle, t_data *data)
{
	float distH;
	float	distV;
	int	dof, mx, my;
	float ra = angle, rx,ry,xo,yo, hx,hy;
	float aTan;
/////////////////////HORIZONTAL/////////////////////
	dof = 0;
	aTan= 1.0/tan(ra);
	if (sin(ra) > 0.001)
	{
		ry = ((py / CUB_SIZE)* CUB_SIZE)  - 0.0001;
		rx = (py - ry)*aTan + px;
		yo = -CUB_SIZE;
		xo = -yo*aTan;
	}
	else if (sin(ra) < -0.001)
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
	if (cos(ra) > 0.001)
	{
		rx = ((px / CUB_SIZE)* CUB_SIZE)  + CUB_SIZE;
		ry = (px - rx)*aTan + py;
		xo = CUB_SIZE;
		yo = -xo*aTan;
	}
	else if (cos(ra) < -0.001)
	{
		rx = ((px / CUB_SIZE)* CUB_SIZE) - 0.0001;
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
	distH = sqrt(((hx-px)*(hx-px)) + ((hy-py)*(hy-py)))  * fabs(cos(ra - data->angl));
	distV = sqrt(((rx-px)*(rx-px)) + ((ry-py)*(ry-py))) * fabs(cos(ra - data->angl));
	if (distV > distH)
	{
		// data->texture.view = 'N';
		data->texture.hit_wall = hx;
		return (distH);
	}
	// if (angle < data->angl)
	// 	data->texture.view = 'E';
	// else
	// 	data->texture.view = 'W';
	data->texture.hit_wall = ry;
	return (distV);
}

float	*draw_walls(t_data *data)
{
	float	*ret;
	int		x;
	float	tmp;
	float	ra = data->angl - (30 * DEGRE);

	ret = malloc(data->win.w  * sizeof(float));
	data->texture.offset_x = malloc(data->win.w  * sizeof(int));
	x = 0;
	while (x < data->win.w)
	{
		tmp = (distance(data->px, data->py, ra, data) / CUB_SIZE);
		if (tmp != 0)
			ret[x] = data->win.h / (2*tmp);
		else
			ret[x] = data->win.h;
		ra += (60 * DEGRE) / data->win.w;
		data->texture.offset_x[x] = (int)data->texture.hit_wall % CUB_SIZE;
		// printf("%d\n", data->texture.offset_x[x]);
		x++;
	}
	return (ret);
}
