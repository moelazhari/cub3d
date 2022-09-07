/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:07:13 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/06 21:04:40 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	check_file(char *file, char *type, t_data *data)
{
	int		i;
	int		len;

	i = 3;
	len = ft_strlen(file) - 1;
	while (i >= 0)
	{
		if (file[len] != type[i])
			exit_error(1, data);
		i--;
		len--;
	}
	i = open(file, O_RDONLY);
	if (i < 0)
		exit_error(1, data);
	return (i);
}

void    get_map(char *file, t_data *data)
{
	int		fd;

    fd = check_file(file, ".cub", data);
}