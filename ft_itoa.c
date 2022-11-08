/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavoribeiro <gustavoribeiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:45:13 by gmorais-          #+#    #+#             */
/*   Updated: 2022/11/07 22:52:30 by gustavoribe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contagem(int n)
{
	if (n > 0)
		return (0);
	return (1);
}

static int	negativo(int n)
{
	if (n > 0)
		return (1);
	return (-1);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*res;
	size_t	len;

	len = contagem(n);
	num = (long)n * negativo(n);
	while (n)
	{
		n /= 10;
		len++;
	}
	res = (char *)malloc(len + 1);
	if (!res)
		return (0);
	*(res + len--) = '\0';
	while (num > 0)
	{
		*(res + len--) = num % 10 + 48;
		num /= 10;
	}
	if (len == 0 && res[1] == '\0')
		*(res + len) = 48;
	else if (len == 0 && res[1] != '\0')
		*(res + len) = '-';
	return (res);
}
/*#include <stdio.h>
int main()
{
	printf("numero 13 -> \t%s\n", ft_itoa (0));
	printf("numero 13 -> \t%s\n", ft_itoa (-14));
}*/