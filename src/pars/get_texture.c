/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:26:58 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/09 15:24:56 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void    get_texture(char *line, t_data *data)
{
	int		w;
	int		h;
	char	*tmp;

	tmp = line;
	if (!ft_strncmp("NO", line, 2) || !ft_strncmp("SO", line, 2) \
|| !ft_strncmp("WO", line, 2) || !ft_strncmp("EA", line, 2))
	{
		tmp = tmp + 2;
		while (ft_strchr(WSPACE, *tmp))
			tmp++;
		check_file(tmp, ".xpm", data);
		if (!ft_strncmp("NO", line, 2) && !data->no)
			data->no = mlx_xpm_file_to_image(data->mlx, tmp, &w, &h);
		else if (!ft_strncmp("SO", line, 2) && !data->so)
			data->so = mlx_xpm_file_to_image(data->mlx, tmp, &w, &h);
		else if (!ft_strncmp("WO", line, 2) && !data->wo)
			data->wo = mlx_xpm_file_to_image(data->mlx, tmp, &w, &h);
		else if (!ft_strncmp("EA", line, 2) && !data->ea)
			data->ea = mlx_xpm_file_to_image(data->mlx, tmp, &w, &h);
		else
			ft_exit("Error doubel identifier", data);
	}
	else
		ft_exit("Error invalid identifier", data);
}