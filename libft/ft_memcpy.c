/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-khad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:30:56 by yel-khad          #+#    #+#             */
/*   Updated: 2021/11/13 16:55:50 by yel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str1;
	char	*str2;

	if (dst == src || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	str1 = (char *)dst;
	str2 = (char *)src;
	while (n--)
		str1[n] = str2[n];
	return (dst);
}
