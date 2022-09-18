/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:16:03 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/18 17:01:24 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <../libft/libft.h>
#include <get_next_line.h>
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

#define	WSPACE	" \t\v\f\r"
#define CUB_SIZE 32
#define DEGRE 0.0174533
#define PI 3.14159265359

#define UP 126
#define DOWN 125
#define RIGHT 124
#define LEFT 123

typedef struct s_map 
{
	int	row;
	int	col;
	char **map;
}
				t_map;

typedef struct s_win
{
	void	*win;
	int		w;
	int		h;
}
				t_win;

typedef struct	s_img {
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_texture{
	t_img		no;
	t_img		so;
	t_img		we;
	t_img		ea;
	float		hit_wall;
	float		hit_wally;
	char		view;
	int			*offset_x;
	int			*offset_y;
}               t_texture;

typedef struct s_data
{
	void		*mlx;
	t_win		win;
	t_img		img;
	t_map		map;
	t_texture	texture;
	float		px;
	float		py;
	float		angl;
	int			f;
	int			c;
	float		*ray;
}				t_data;

void    pars_file(char *file, t_data *data);
int		check_file(char *file, char *type, t_data *data);
void    get_color(char *line, t_data *data);
void    get_map(int fd, t_data  *data);
void	check_map(t_data *data);
void	generate_game(t_data *data);
void	ft_exit(char *error_msg, t_data *data);
float	*draw_walls(t_data *data);
int		key_handler(int key, t_data *data);
float	distance(int px, int py, float angle, t_data *data);
#endif