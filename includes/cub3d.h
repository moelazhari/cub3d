/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-khad <yel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:16:03 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/13 19:04:05 by yel-khad         ###   ########.fr       */
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
#define WIDTH	32
#define HEIGHT	32
#define PIXELS  16
#define DEGRE 0.0174533
#define PI 3.14159265359


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
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_data
{
	void		*mlx;
	t_win		win;
	t_img		img;
	t_map		map;
	int			px;
	int			py;
	int			dx;
	int			dy;
	int			dist;
	float		angl;
	char		view;
	void		*no;
	void		*so;
	void		*wo;
	void		*ea;
	int			f;
	int			c;
	int			*ray;
}				t_data;

void    pars_file(char *file, t_data *data);
int		check_file(char *file, char *type, t_data *data);
void    get_color(char *line, t_data *data);
void    get_map(int fd, t_data  *data);
void	check_map(t_data *data);
void	generate_game(t_data *data);
void	render_game(t_data *data);
void	ft_exit(char *error_msg, t_data *data);
int		*draw_walls(t_data *data);
int		key_handler(int key, t_data *data);
int		distance(int px, int py, float angle, t_data *data);
#endif