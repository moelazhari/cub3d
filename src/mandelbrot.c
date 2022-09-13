/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-khad <yel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:23:05 by yel-khad          #+#    #+#             */
/*   Updated: 2022/09/13 19:09:04 by yel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	distance(int px, int py, float angle, t_data *data)
{
	int distH;
	int	distV;
	int	dof, mx, my;
	float ra = angle, rx,ry,xo,yo, hx,hy;	
	float aTan;
	int ret;
	
/////////////////////HORIZONTAL/////////////////////
		dof = 0;
		aTan= 1.0/tan(ra);
		if (sin(ra) > 0.001)
		{
			ry = ((py / WIDTH)* WIDTH)  - 0.0001;
			rx = (py - ry)*aTan + px;
			yo = -WIDTH;
			xo = -yo*aTan;
		}
		else if (sin(ra) < -0.001)
		{
			ry = ((py / WIDTH)* WIDTH) + WIDTH;
			rx = (py - ry)*aTan + px;
			yo = WIDTH;
			xo = -yo*aTan;
		}
		else
		{
			dof = 10;
		}
		while (dof < 10)
		{
			mx = (int)(rx) / WIDTH;
			my = (int)(ry) / WIDTH;
			if (mx >= 0 && mx <= 9 && my <= 9 && my >= 0 && data->map.map[abs(my)][abs(mx)] == '1')
				dof =10;
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
			rx = ((px / WIDTH)* WIDTH)  + WIDTH;
			ry = (px - rx)*aTan + py;
			xo = WIDTH;
			yo = -xo*aTan;
		}
		else if (cos(ra) < -0.001)
		{
			rx = ((px / WIDTH)* WIDTH) - 0.0001;
			ry = (px - rx)*aTan + py;
			xo = -WIDTH;
			yo = -xo*aTan;
		}
		else
		{
			dof = 10;
		}
		while (dof < 10)
		{
			mx = (int)(rx) / WIDTH;
			my = (int)(ry) / WIDTH;
			if (mx >= 0 && mx <= 9 && my <= 9 && my >= 0 && data->map.map[abs(my)][abs(mx)] == '1')
				dof =10;
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
		if (distV > distH)
		{
			ret = (PIXELS*60 - distH)/2;
		}
		else 
		{
			ret = (PIXELS*60 - distV)/2;
		}
		return (ret);
}

int	*draw_walls(t_data *data)
{
	int	*ret;
	int r = 0;
	float ra = data->angl - (30*DEGRE);

	ret = malloc(60 * sizeof(int));
	while (r < 60)
	{
		ret[r] = distance(data->px, data->py, ra, data);
		// if (r==30)
		// 	printf("dist===%d\n",ret[r]);
		// if (ret[r] >= )
		// 	ret[r] = 479;
		ra += DEGRE;
		r++;
	}
	printf("data->px===%d\ndata->py===%d\n",data->px,data->py);
	
	return (ret);
}
