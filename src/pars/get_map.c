/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:22:34 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/10 17:59:30 by mazhari          ###   ########.fr       */
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
		new[i] = data->map.map[i];
		i++;
	}
	new[i] = line;
	new[i + 1] = NULL;
    free(data->map.map);
	data->map.map = new;
}



void    get_map(int fd, t_data  *data)
{
    char	*line;
	
	line = get_next_line(fd);
	if (!line)
		ft_exit("Error map", data);
    while (line[0] == '\n')
        line = get_next_line(fd);
    while (line)
    {
		line = ft_strtrim(line, "\n");
        fill_map(line, data);
        line = get_next_line(fd);
    }
    check_map(data);
    // for (int i = 0; data->map.map[i]; i++)
    //     printf("%s", data->map.map[i]);
}