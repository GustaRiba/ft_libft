/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:57:28 by gmorais-          #+#    #+#             */
/*   Updated: 2022/11/07 12:09:02 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char const *str, char separ)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (*str)
	{
		if (*str != separ && flag == 0)
		{
			flag = 1;
			i++;
		}
		else if (*str == separ)
			flag = 0;
		str++;
	}
	return (i);
}

static int	ft_size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		wordsize;
	char	**newstr;
	int		j;
	int		strsize;

	i = 0;
	j = -1;
	wordsize = wordcount(s, c);
	newstr = malloc((wordsize + 1) * sizeof(char *));
	if (!newstr)
		return (NULL);
	while (++j < wordsize)
	{
		while (s[i] == c)
			i++;
		strsize = ft_size_word(s, c, i);
		newstr[j] = ft_substr(s, i, strsize);
		i += strsize;
	}
	newstr[j] = '\0';
	return (newstr);
}
