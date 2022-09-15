/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-khad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:52:33 by yel-khad          #+#    #+#             */
/*   Updated: 2021/11/18 18:53:58 by yel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;

	if (!dst && !src)
	{
		*dst = '\0';
		return (0);
	}
	srcsize = ft_strlen(src);
	if (!dstsize)
		return (srcsize);
	while (--dstsize && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (srcsize);
}
