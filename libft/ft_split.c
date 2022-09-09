/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:41:02 by yel-khad          #+#    #+#             */
/*   Updated: 2022/09/09 19:15:05 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	nbr_words(char const *s, char c)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (s == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i])
			k++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (k);
}

static size_t	strlen_c(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*strdup_c(const char *s, char c)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc((strlen_c(s, c) + 1) * sizeof(char));
	while (s[i] && s[i] != c)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static void	ft_free(char c, char const *s, size_t *j, char **stock)
{
	while (*j > 0)
		free(stock[--*j]);
	free(stock);
	*j = nbr_words(s, c) - 1;
}

char	**ft_split(char const *s, char c)
{
	char	**stock;
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	if (s == 0)
		return (0);
	if (s[i] == c || s[ft_strlen(s) - 1] == c || nbr_words(s, c) != 3)
		return (0);
	stock = malloc(sizeof(char *) * (nbr_words(s, c) + 1));
	if (!stock)
		return (0);
	while (j < nbr_words(s, c))
	{
		if (s[i] == c)
			i++;
		stock[j] = strdup_c(s + i, c);
		if (!stock[j])
			ft_free(c, s, &j, stock);
		j++;
		while (s[i] != c && s[i])
			i++;
	}
	stock[j] = 0;
	return (stock);
}
