/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 08:12:19 by ktwomey           #+#    #+#             */
/*   Updated: 2018/06/07 09:49:11 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_neg(char *str, int n)
{
	int i;

	i = ft_intlen(n);
	n = -n;
	if (n == 0)
		str = "0";
	while (i != 0)
	{
		i--;
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	str[i] = '-';
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_intlen(n);
	if (!(str = (char*)malloc(sizeof(*str) + 1 * i)))
		return (NULL);
	if (n == -2147483648)
	{
		str = ft_strcpy(str, "-2147483648");
		return (str);
	}
	str[i] = '\0';
	if (n < 0)
	{
		str = ft_itoa_neg(str, n);
	}
	else
		while (i != -1)
		{
			--i;
			str[i] = n % 10 + '0';
			n = n / 10;
		}
	return (str);
}
