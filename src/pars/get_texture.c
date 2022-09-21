/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:32:05 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/21 15:01:01 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void check_no(char *path, t_data *data, int *w, int *h)
{
    data->texture.no.img = mlx_xpm_file_to_image(data->mlx, path, w, h);
        if (!data->texture.no.img)
            ft_exit("Error texture", data);
}

static void check_texture(char *line, char *path, t_data *data, int *w, int *h)
{
    if (!ft_strncmp("NO", line, 2) && !data->texture.no.img)
        check_no(path, data, w, h);
    else if (!ft_strncmp("SO", line, 2) && !data->texture.so.img)
    {
        data->texture.so.img = mlx_xpm_file_to_image(data->mlx, path, w, h);
             if (!data->texture.so.img)
                ft_exit("Error texture", data);
    }    
    else if (!ft_strncmp("WE", line, 2) && !data->texture.we.img)
    {
        data->texture.we.img = mlx_xpm_file_to_image(data->mlx, path, w, h);
             if (!data->texture.we.img)
                ft_exit("Error texture", data);
    }
    else if (!ft_strncmp("EA", line, 2) && !data->texture.ea.img)
    {
        data->texture.ea.img = mlx_xpm_file_to_image(data->mlx, path, w, h);
            if (!data->texture.ea.img)
                ft_exit("Error texture", data);
    }
    else
        ft_exit("Error doubel identifier", data);
}

void    get_texture(char *line, t_data *data)
{
	char	*tmp;
    int     w;
    int     h;

	tmp = line;
	if (!ft_strncmp("NO", line, 2) || !ft_strncmp("SO", line, 2) \
|| !ft_strncmp("WE", line, 2) || !ft_strncmp("EA", line, 2))
	{
        tmp = tmp + 2;
        if (!ft_strchr(WSPACE, *tmp))
            ft_exit("Error invalid identifier", data);
        while (ft_strchr(WSPACE, *tmp))
            tmp++;
        check_texture(line, tmp, data, &w, &h);
	}
	else
		ft_exit("Error invalid identifier", data);
}
