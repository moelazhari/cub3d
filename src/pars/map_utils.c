/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 19:28:34 by mazhari           #+#    #+#             */
/*   Updated: 2022/09/09 16:16:06 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_file(char *file, char *type, t_data *data)
{
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
	i = open(file, O_RDONLY);
	if (i < 0)
		ft_exit("Error file not found", data);
	return (i);
}