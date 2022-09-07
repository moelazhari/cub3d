/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:16:03 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/06 19:52:51 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <../libft/libft.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_player
{
	int		row;
	int		col;
	char	view;
}				t_player;

typedef struct s_data
{
	char        **map;
	t_player    *player;
}				t_data;

void    get_map(char *file, t_data *data);
void    exit_error(int error, t_data *data);

#endif