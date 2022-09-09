/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-khad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 12:02:26 by yel-khad          #+#    #+#             */
/*   Updated: 2021/11/18 18:49:51 by yel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_in(char c, char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	strlen_set(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (ft_in(s1[i], set))
		i++;
	k = i;
	if (!s1[i])
		return (k);
	while (ft_in(s1[ft_strlen(s1) - 1 - j], set))
		j++;
	k = k + j;
	return (ft_strlen(s1) - k);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (0);
	str = malloc(strlen_set(s1, set) + 1);
	if (!str)
		return (0);
	while (ft_in(s1[i], set))
		i++;
	while (j < strlen_set(s1, set))
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}
