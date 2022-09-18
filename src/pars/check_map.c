/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:45:25 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/18 14:50:07 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void check_surrounded(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			ft_exit("Error map", data);
		i++;
	}
}

// static void check_space(int row, int col, t_data *data)
// {
// 	if ((data->map.map[row][col + 1] != ' ' && data->map.map[row][col + 1] != '1')\
//  || (data->map.map[row - 1][col] != ' ' && data->map.map[row - 1][col] != '1'))
//  	{
// 			ft_exit("Error map", data);
// 	}
// }

static void check_flor_player(int row, int col, t_data *data)
{
	if (col > (int)ft_strlen(data->map.map[row - 1]) - 1\
 || col > (int)ft_strlen(data->map.map[row + 1]) - 1)
		ft_exit("Error map", data);
	if ((data->map.map[row][col + 1] == ' ') 
 || (data->map.map[row][col - 1] == ' ' )\
 || (data->map.map[row + 1][col] == ' ')\
 || (data->map.map[row - 1][col] == ' '))
 	{
		ft_exit("Error map", data);
	}
}

static void	check_inside(char c, int row, int col, t_data *data)
{
	if (c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'E'\
 && c != 'W' && c != ' ')
 	{
		 printf("dsgsfg\n");
		ft_exit("Error map", data);
	}
	else if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		check_flor_player(row, col, data);
		if (c != '0')
		{
			data->px = (col * CUB_SIZE) + 16;
			data->py = (row * CUB_SIZE) + 16;
			if (data->angl != -1)
				ft_exit("Error map", data);
			else if (c == 'N')
				data->angl = (PI / 2);
			else if (c == 'S')
				data->angl = PI + (PI/ 2);
			else if (c == 'E')
				data->angl = 0;
			else if (c == 'W')
				data->angl = PI;
			
		}
	}
}

void	check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
    if (data->map.row < 3)
        ft_exit("Error map", data);
    check_surrounded(data->map.map[i], data);
    i++;
	while (i < data->map.row - 1)
	{
		j = 0;
		if (data->map.map[i][j] != ' ' && data->map.map[i][j] != '1')
			ft_exit("Error map", data);
		j++;
		while (data->map.map[i][j])
		{
			check_inside(data->map.map[i][j], i, j, data);
			j++;
		}
		if (data->map.map[i][j - 1] != ' ' && data->map.map[i][j - 1] != '1')
			ft_exit("Error map", data);
		i++;
	}
	if (data->angl == -1)
		ft_exit("Error map", data);
	check_surrounded(data->map.map[i], data);
}