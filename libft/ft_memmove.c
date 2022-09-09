/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-khad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:55:36 by yel-khad          #+#    #+#             */
/*   Updated: 2021/11/11 19:08:19 by yel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memmove(void *dst, const void *src, int len)
{
	char		*str1;
	const char	*str2;

	if (dst == src)
		return (dst);
	str1 = (char *)dst;
	str2 = (const char *)src;
	if (str1 < str2)
	{
		while (len--)
			*str1++ = *str2++;
		return (dst);
	}
	while (len--)
		str1[len] = str2[len];
	return (dst);
}
