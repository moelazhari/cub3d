/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:07:13 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/08 16:09:19 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	*pars_rgb(char **rgb, t_data *data)
{
	int	i;
	int	j;
	int	*hexa;

	i = 0;
	while (rgb[i])
		i++;
	if (i !=3)
		ft_exit("Error invalid rgb", data);
	hexa = malloc(sizeof(int) * 3);
	i = 0;
	while (rgb[i])
	{
		if (i == 2)
			rgb[i] = rm_char(rgb[i]);
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]))
				ft_exit("Error invalid rgb", data);
			j++;
		}
		hexa[i] = ft_atoi(rgb[i]);
		if (hexa[i] < 0 || hexa[i] > 255)
			ft_exit("Error invalid rgb", data);
		i++;
	}
	return (hexa);
}

void    get_color(char *line, t_data *data)
{
	char	*tmp;
	char	**split;
	int		*rgb;
	
	tmp = line;
	if (!ft_strncmp("F", line, 1) || !ft_strncmp("C", line, 1))
	{
		tmp++;
		while (ft_strchr(WSPACE, *tmp))
			tmp++;
		split = ft_split(tmp, ',');
		rgb = pars_rgb(split, data);
		if (!ft_strncmp("F", line, 1))
			data->f = 1; //get_hexa(rgb, data);
		else
			data->c = 1; //get_hexa(rgb, data);
	}
	else
		ft_exit("Error invalid identifier", data);

}

static	int	check_texture_color(t_data *data)
{
	if (data->no == NULL || data->so == NULL || data->wo == NULL \
|| data->ea == NULL || data->f == 0 || data->c == 0)
		return (0);

	return(1);
}

static void get_texture_color(int fd, t_data *data)
{
	char	*line;
	char	**split;
	
	line = get_next_line(fd); 
	if (!line)
			ft_exit("Error file empty", data);
	while (line && !check_texture_color(data))
	{
		split = ft_split(line, "");
		if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E'\
 || line[0] == 'F' || line[0] == 'C' || line[0] == '\n')
		{
			if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E')
				get_texture(line, data);
			else if (line[0] == 'F' || line[0] == 'C')
				get_color(line, data);
		}
		else
		{
			if (!check_texture_color(data))
				ft_exit("Error invalid identifier", data);
		}
		line = get_next_line(fd);
	}
	if (!check_texture_color(data))
				ft_exit("Error texture not found", data);
}

void    get_map(char *file, t_data *data)
{
	int		fd;

    fd = check_file(file, ".cub", data);
	get_texture_color(fd, data);
}