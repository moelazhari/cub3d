/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-khad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 23:02:42 by yel-khad          #+#    #+#             */
/*   Updated: 2021/11/18 18:15:28 by yel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	if (len <= ft_strlen(s + start))
		str = malloc(len + 1);
	else
		str = malloc(ft_strlen(s + start) + 1);
	if (!str)
		return (0);
	while (i < len && start < ft_strlen(s))
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
