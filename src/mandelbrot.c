/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-khad <yel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:23:05 by yel-khad          #+#    #+#             */
/*   Updated: 2022/09/12 19:43:55 by yel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

// static int	converge_mandelbrot(t_data data, double x, double y, int *c)
// {
// 	int		i;
// 	double	a;
// 	double	b;
// 	double	tmp;

// 	i = 0;
// 	(void) c;
// 	x = (x * (data.ref->x_max - data.ref->x_min) / SIZE) + data.ref->x_min;
// 	y = (y * (data.ref->y_max - data.ref->y_min) / SIZE) + data.ref->y_min;
// 	a = x;
// 	b = y;
// 	while (i < data.iter && (a * a) + (b * b) < 4)
// 	{
// 		tmp = a;
// 		a = ((a * a) - (b * b)) + x;
// 		b = (2 * tmp * b) + y;
// 		i++;
// 	}
// 	if ((a * a) + (b * b) < 4)
// 		return (1);
// 	else
// 	return (0);
// }

int	*draw_image_mandelbrot(t_data *data)
{
	int	x;
	int	y;
	int	i;
	int	j;
	double deltaX; 
	double deltaY;
	int pixels;
	double pixelX;
	double pixelY;
	int	dof, r=0, mx, my;
	float ra = data->angl - 0.6, rx,ry,xo,yo, hx,hy;	
	float aTan;
	int	*ret;

	ret = malloc(32 * data->map.col * sizeof(int));
	while (r < 32 * data->map.col)
	{
/////////////////////HORIZONTAL/////////////////////
		dof = 0;
		aTan= 1.0/tan(6.28 - ra);
		if (sin(6.28 - ra) > 0.001)
		{
			ry = ((data->py / WIDTH)* WIDTH)  - 0.0001;
			rx = (data->py - ry)*aTan + data->px;
			yo = -WIDTH;
			xo = -yo*aTan;
		}
		else if (sin(6.28 - ra) < -0.001)
		{
			ry = ((data->py / WIDTH)* WIDTH) + WIDTH;
			rx = (data->py - ry)*aTan + data->px;
			yo = WIDTH;
			xo = -yo*aTan;
		}
		else
		{
			// ry= data->py;
			// rx = data->px;
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
		printf("HORIZONTAL:RX=%d||||RY=%d\n", (int)rx,(int)ry);
/////////////////////VERTICAL//////////////////
		dof = 0;
		aTan= tan(6.28 - ra);
		if (cos(6.28 - ra) > 0.001)
		{
			rx = ((data->px / WIDTH)* WIDTH)  + WIDTH;
			ry = (data->px - rx)*aTan + data->py;
			xo = WIDTH;
			yo = -xo*aTan;
		}
		else if (cos(6.28 - ra) < -0.001)
		{
			rx = ((data->px / WIDTH)* WIDTH) - 0.0001;
			ry = (data->px - rx)*aTan + data->py;
			xo = -WIDTH;
			yo = -xo*aTan;
		}
		else
		{
			// rx = data->px;
			// ry= data->py;
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
		ra += 0.001;
		// printf("VERTICAL:RX=%d||||RY=%d\n", (int)rx,(int)ry);
	if (sqrt(((rx-data->px)*(rx-data->px)) + ((ry-data->py)*(ry-data->py))) > sqrt(((hx-data->px)*(hx-data->px)) + ((hy-data->py)*(hy-data->py))))
	{
		ret[r] = sqrt(((hx-data->px)*(hx-data->px)) + ((hy-data->py)*(hy-data->py)));
	}
	else 
	{
		ret[r] = sqrt(((rx-data->px)*(rx-data->px)) + ((ry-data->py)*(ry-data->py)));
	}
		r++;
	}
	return (ret);
////////////////////////////////////////////////
}

// void	mandelbrot(t_ref *ref, char **map)
// {
// 	t_data	data;

// 	// pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
// 	// deltaX /= pixels;
// 	// deltaY /= pixels;
// 	// pixelX = data->px;
// 	// pixelY = data->py;
// 	// while (pixels)
// 	// {
// 	// 	my_mlx_pixel_put(data, pixelX, pixelY , c * 888888);
//     // 	pixelX += deltaX;
//     // 	pixelY += deltaY;
//     // 	--pixels;
// 	// }
// 	ref->x_max = 2;
// 	ref->y_max = 2;
// 	ref->x_min = -2;
// 	ref->y_min = -2;
// 	data.x = 'm';
// 			data.angl = 0;
// 			data.dx = cos(data.angl) * 5;
// 			data.dy = sin(data.angl) * 5;
// 	data.px = WIDTH / 2.1;
// 	data.py = HIGHT / 1.5;
// 	data.iter = 200;
// 	data.ref = ref;
// 	data.map = map;
// 	data.mlx = mlx_init();
// 	data.win = mlx_new_window(data.mlx, WIDTH, HIGHT, "Mandelbort");
// 	data.img = mlx_new_image(data.mlx, WIDTH, HIGHT);
// 	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
// 			&data.line_length, &data.endian);
// 	draw_image_mandelbrot(&data);
// 	mlx_key_hook(data.win, key_handler, &data);
// 	mlx_mouse_hook(data.win, zoom, &data);
// 	mlx_hook(data.win, 17, 0, exit_, &data);
// 	mlx_loop(data.mlx);
// }
