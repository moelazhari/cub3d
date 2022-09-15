/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:23:20 by yel-khad          #+#    #+#             */
/*   Updated: 2022/09/15 16:15:15 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
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
// 	data.px = CUB_SIZE / 2.1;
// 	data.py = HIGHT / 1.5;
// 	data.iter = 200;
// 	data.ref = ref;
// 	data.map = map;
// 	data.mlx = mlx_init();
// 	data.win = mlx_new_window(data.mlx, CUB_SIZE, HIGHT, "Mandelbort");
// 	data.img = mlx_new_image(data.mlx, CUB_SIZE, HIGHT);
// 	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
// 			&data.line_length, &data.endian);
// 	draw_image_mandelbrot(&data);
// 	mlx_key_hook(data.win, key_handler, &data);
// 	mlx_mouse_hook(data.win, zoom, &data);
// 	mlx_hook(data.win, 17, 0, exit_, &data);
// 	mlx_loop(data.mlx);
// }
static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

static double	ft_atoi(char *str)
{
	int		i;
	int		j;
	double	s;
	int		res;

	i = 0;
	j = 0;
	res = 0;
	s = 1 - (2 * (str[i] == '-'));
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '.')
		res = (res * 10) + str[i++] - '0';
	if (str[i] == '.')
		j = ++i;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + str[i++] - '0';
	j = i - j;
	while (j--)
		s = s / 10;
	return ((double)(s * res));
}

static void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int ac, char **av)
{
	t_ref	*ref;
 char map[] = "   1011111:1111010001:1000010001:1000110001:1000000001:1000000001:1000000001:1000000001:1000000001:1111111111";
//  char map[] = " 1011111:11010001:00010001:00110001:00000001:00000001:00000001:00000001:00000001:11111111";
	ref = malloc(sizeof(t_ref));
	if (!ref)
		return (0);
	if (ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		mandelbrot(ref, ft_split(map, ':'));
	else if (ac == 4 && !ft_strcmp(av[1], "julia"))
		julia(ft_atoi(av[2]), ft_atoi(av[3]), ref);
	else
		ft_putstr(">./fractol mandelbrot\nor\n>./fractol julia \
[parameter1] [parameter2]\nParameters of classic julia \
sets:\n0.3\t0.5\n0.285\t0.01\n-0.4\t0.6\n-0.8\t0.156");
	free(ref);
	return (0);
}
