/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-khad <yel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:23:20 by yel-khad          #+#    #+#             */
/*   Updated: 2022/09/11 16:32:32 by yel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

static double	ft_atoi(char *str)
{
	int		i;
	int		j;
	double	s;
	int		res;

	i = 0;
	j = 0;
	res = 0;
	s = 1 - (2 * (str[i] == '-'));
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '.')
		res = (res * 10) + str[i++] - '0';
	if (str[i] == '.')
		j = ++i;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + str[i++] - '0';
	j = i - j;
	while (j--)
		s = s / 10;
	return ((double)(s * res));
}

static void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int ac, char **av)
{
	t_ref	*ref;
 char map[] = "   1011111:1111010001:1000010001:1000110001:1000000001:1000000001:1000000001:1000000001:1000000001:1111111111";
//  char map[] = " 1011111:11010001:00010001:00110001:00000001:00000001:00000001:00000001:00000001:11111111";
	ref = malloc(sizeof(t_ref));
	if (!ref)
		return (0);
	if (ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		mandelbrot(ref, ft_split(map, ':'));
	else if (ac == 4 && !ft_strcmp(av[1], "julia"))
		julia(ft_atoi(av[2]), ft_atoi(av[3]), ref);
	else
		ft_putstr(">./fractol mandelbrot\nor\n>./fractol julia \
[parameter1] [parameter2]\nParameters of classic julia \
sets:\n0.3\t0.5\n0.285\t0.01\n-0.4\t0.6\n-0.8\t0.156");
	free(ref);
	return (0);
}
