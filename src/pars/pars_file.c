/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:07:13 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/23 18:48:37 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_file(char *file, char *type, t_data *data)
{
	int		fd;
	int		i;
	int		len;	

	i = ft_strlen(type) - 1;
	len = ft_strlen(file) - 1;
	while (i >= 0)
	{
		if (file[len] != type[i])
			ft_exit("Error wrong file type", data);
		i--;
		len--;
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit("Error file not found", data);
	return (fd);
}

static int	check_texture_color(t_data *data)
{
	if (data->texture.no.img == NULL || data->texture.so.img == NULL || data->texture.we.img == NULL \
|| data->texture.ea.img == NULL || data->f == 0 || data->c == 0)
		return (0);
	return(1);
}

static char *get_texture_color(int fd, t_data *data)
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
		free(line);
		line = get_next_line(fd);
	}
	if (!check_texture_color(data))
		ft_exit("Error texture not found", data);
	return (line);
}

static void get_texture_pixsls(t_data *data)
{
    data->texture.no.addr = (int *)mlx_get_data_addr(data->texture.no.img,\
 &data->texture.no.bits_per_pixel, &data->texture.no.line_length,\
 &data->texture.no.endian);
	data->texture.so.addr = (int *)mlx_get_data_addr(data->texture.so.img,\
 &data->texture.so.bits_per_pixel, &data->texture.so.line_length,\
 &data->texture.so.endian);
	data->texture.we.addr = (int *)mlx_get_data_addr(data->texture.we.img,\
 &data->texture.we.bits_per_pixel, &data->texture.we.line_length,\
 &data->texture.we.endian);
 	data->texture.ea.addr = (int *)mlx_get_data_addr(data->texture.ea.img,\
 &data->texture.ea.bits_per_pixel, &data->texture.ea.line_length,\
 &data->texture.ea.endian);
}

void	pars_file(char *file, t_data *data)
{
	int		fd;
	char	*line;

    fd = check_file(file, ".cub", data);
	line = get_texture_color(fd, data);
	get_texture_pixsls(data);
	get_map(fd, line, data);
}