/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-khad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:57:42 by yel-khad          #+#    #+#             */
/*   Updated: 2021/11/15 15:46:36 by yel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

static unsigned int	nbrlen(unsigned int n)
{
	unsigned int	i;
	long			x;

	i = 1;
	x = 10;
	while (n % x != n)
	{
		x = x * 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long			x;
	unsigned int	i;
	unsigned int	k;
	long			nbr;
	char			*str;

	x = 1;
	i = 0;
	k = (n < 0);
	nbr = (1 - (2 * k)) * n;
	str = malloc(sizeof(char) * (nbrlen(nbr) + 1 + k));
	if (!str)
		return (NULL);
	if (k)
		str[0] = '-';
	while ((x * 10) <= nbr)
		x = x * 10;
	while (i < nbrlen(nbr))
	{
		str[i + k] = ((nbr / x) % 10) + 48;
		x = x / 10;
		i++;
	}
	str[i + k] = '\0';
	return (str);
}
