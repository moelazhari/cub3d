/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:16:03 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/11 13:34:54 by mazhari          ###   ########.fr       */
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

#define	WSPACE " \t\v\f\r"

typedef struct s_player
{
	int		row;
	int		col;
	char	view;
	int		count;
}				t_player;

typedef struct s_map 
{
	int	row;
	int	col;
	char **map;
}
				t_map;

typedef struct s_data
{
	void		*mlx;
	t_map		map;
	t_player    player;
	void		*no;
	void		*so;
	void		*wo;
	void		*ea;
	int			f;
	int			c;
}				t_data;

void    pars_file(char *file, t_data *data);
int		check_file(char *file, char *type, t_data *data);
void    get_color(char *line, t_data *data);
void    get_map(int fd, t_data  *data);
void	check_map(t_data *data);
void	ft_exit(char *error_msg, t_data *data);

#endif