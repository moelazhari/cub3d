/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:07:13 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/09 19:29:40 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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
	
	line = get_next_line(fd); 
	if (!line)
			ft_exit("Error file empty", data);
	while (line && !check_texture_color(data))
	{
		line = ft_strtrim(line, " \t\v\f\r\n");
		if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W' || line[0] == 'E'\
 || line[0] == 'F' || line[0] == 'C' || line[0] == '\0')
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

void    pars_file(char *file, t_data *data)
{
	int		fd;

    fd = check_file(file, ".cub", data);
	get_texture_color(fd, data);
}