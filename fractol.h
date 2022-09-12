/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-khad <yel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:23:31 by yel-khad          #+#    #+#             */
/*   Updated: 2022/09/10 15:39:26 by yel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define SIZE 5 * COL_N * LIN_N
# define HIGHT LIN_N * PIXELS
# define WIDTH COL_N * PIXELS
# define COL_N 10
# define LIN_N 10
# define PIXELS 100
# define EAST 0
# define WEST 3.14
# define NORTH 3*3.14/2
# define SOUTH 3.14/2
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
 #include <math.h>

typedef struct s_ref
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}	t_ref;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		iter;
	int		px;
	int		py;
	float	angl;
	float	dx;
	float	dy;
	char	**map;
	char	x;
	double	cr;
	double	ci;
	t_ref	*ref;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_image_mandelbrot(t_data *data);
void	draw_image_julia(t_data *data);
int		zoom(int key, int x, int y, t_data *data);
int		key_handler(int key, t_data *data);
int		exit_(int key, t_data *data);
void	mandelbrot(t_ref *ref, char **map);
void	julia(double cr, double ci, t_ref *ref);
char	**ft_split(char const *s, char c);

#endif
