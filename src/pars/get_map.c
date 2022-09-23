/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:22:34 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/23 18:50:53 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	fill_map(char *line, t_data *data)
{
	char	**new;
	int	i;

	i = 0;
	data->map.row = data->map.row + 1;
	new = malloc(sizeof(char *) * (data->map.row + 1));
	if (!new)
		ft_exit("Error malloc", data);
	while (data->map.map && data->map.map[i])
	{
		new[i] = ft_strdup(data->map.map[i]);
		i++;
	}
	new[i] = line;
	new[i + 1] = NULL;
	ft_freearr(data->map.map);
	data->map.map = new;
}

static void get_colmn(t_data *data)
{
	int		max;
	int		i;

	max = 0;
	i = 0;
	while (data->map.map[i])
	{
		if ((int)ft_strlen(data->map.map[i]) > max)
			max = ft_strlen(data->map.map[i]);
		i++;
	}
	data->map.col = max;
}

void    get_map(int fd, char *line, t_data  *data)
{
    while (line && line[0] == '\n')
	{
		free(line);
        line = get_next_line(fd);
	}
	if (!line)
		ft_exit("Error map", data);
    while (line && line[0] != '\n')
    {
		line = ft_strtrim(line, "\n");
        fill_map(line, data);
        line = get_next_line(fd);
    }
    check_map(data);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		ft_exit("Error map", data);
	get_colmn(data);
}