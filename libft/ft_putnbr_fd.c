/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-khad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:03:45 by yel-khad          #+#    #+#             */
/*   Updated: 2021/11/19 18:28:07 by yel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	x;
	long	nbr;

	x = 10;
	nbr = (1 - 2 * (n < 0)) * n;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (x <= nbr)
		x = x * 10;
	while (x != 1)
	{
		x = x / 10;
		ft_putchar_fd((nbr / x) % 10 + 48, fd);
	}
}
