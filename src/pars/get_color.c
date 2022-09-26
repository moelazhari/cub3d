/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:14:32 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/25 15:11:50 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	*pars_rgb(char **split, t_data *data)
{
	int	i;
	int	j;
	int	*rgb;

	i = 0;
	rgb = malloc(sizeof(int) * 3);
	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (!ft_isdigit(split[i][j]))
				ft_exit("Error invalid rgb", data);
			j++;
		}
		rgb[i] = ft_atoi(split[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			ft_exit("Error invalid rgb", data);
		i++;
	}
	ft_freearr(split);
	return (rgb);
}

static int	get_hexa(int *rgb)
{
	int	hexa;
	int	i;

	i = 0;
	hexa = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	free((void *)rgb);
	return (hexa);
}

void	get_color(char *line, t_data *data)
{
	char	*tmp;
	char	**split;
	int		*rgb;

	tmp = line;
	if (!ft_strncmp("F", line, 1) || !ft_strncmp("C", line, 1))
	{
		tmp++;
		if (!ft_strchr(WSPACE, *tmp))
			ft_exit("Error invalid identifier", data);
		while (ft_strchr(WSPACE, *tmp))
			tmp++;
		split = ft_split(tmp, ',');
		if (!split)
			ft_exit("Error invalid rgb", data);
		rgb = pars_rgb(split, data);
		if (!ft_strncmp("F", line, 1))
			data->f = get_hexa(rgb);
		else
			data->c = get_hexa(rgb);
	}
	else
		ft_exit("Error invalid identifier", data);
}
