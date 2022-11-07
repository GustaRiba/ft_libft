/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:49:44 by gmorais-          #+#    #+#             */
/*   Updated: 2022/11/04 14:21:46 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*prt;

	s_len = ft_strlen(s);
	if (start > s_len)
	{
		prt = malloc(sizeof(char));
		*prt = 0;
		return (prt);
	}
	if (len >= s_len)
		len = s_len - start;
	prt = malloc(len + 1);
	if (!prt)
		return (NULL);
	prt[len] = '\0';
	return (ft_memcpy(prt, s + start, len));
}

/*#include <stdio.h>
int main()
{
	char teste[] = "paulochatoparacaralho";
	printf("%s", ft_substr(teste, 422, 5));
}*/