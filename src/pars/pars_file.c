/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:07:13 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/17 14:27:16 by mazhari          ###   ########.fr       */
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

static void    get_texture(char *line, t_data *data)
{
	int		w;
	int		h;
	char	*tmp;

	tmp = line;
	if (!ft_strncmp("NO", line, 2) || !ft_strncmp("SO", line, 2) \
|| !ft_strncmp("WO", line, 2) || !ft_strncmp("EA", line, 2))
	{
		tmp = tmp + 2;
		if (!ft_strchr(WSPACE, *tmp))
			ft_exit("Error invalid identifier", data);
		while (ft_strchr(WSPACE, *tmp))
			tmp++;
		check_file(tmp, ".xpm", data);
		if (!ft_strncmp("NO", line, 2) && !data->texture.no)
			data->texture.no = mlx_xpm_file_to_image(data->mlx, tmp, &w, &h);
		else if (!ft_strncmp("SO", line, 2) && !data->texture.so)
			data->texture.so = mlx_xpm_file_to_image(data->mlx, tmp, &w, &h);
		else if (!ft_strncmp("WO", line, 2) && !data->texture.wo)
			data->texture.wo = mlx_xpm_file_to_image(data->mlx, tmp, &w, &h);
		else if (!ft_strncmp("EA", line, 2) && !data->texture.ea)
			data->texture.ea = mlx_xpm_file_to_image(data->mlx, tmp, &w, &h);
		else
			ft_exit("Error doubel identifier", data);
	}
	else
		ft_exit("Error invalid identifier", data);
}

static	int	check_texture_color(t_data *data)
{
	if (data->texture.no == NULL || data->texture.so == NULL || data->texture.wo == NULL \
|| data->texture.ea == NULL || data->f == 0 || data->c == 0)
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

void	pars_file(char *file, t_data *data)
{
	int		fd;

    fd = check_file(file, ".cub", data);
	get_texture_color(fd, data);
	get_map(fd, data);
	// printf("row: %d col: %d\n", data->map.row, data->map.col);
}