/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-khad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:49:13 by yel-khad          #+#    #+#             */
/*   Updated: 2021/11/18 18:52:58 by yel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_size;
	size_t	dst_size;
	int		i;

	i = 0;
	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	if (!dstsize || dstsize <= dst_size)
		return (src_size + dstsize);
	while (dst[i])
		i++;
	while (*src && dst_size < --dstsize)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (src_size + dst_size);
}
