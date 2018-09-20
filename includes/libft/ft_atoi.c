/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 09:48:31 by ktwomey           #+#    #+#             */
/*   Updated: 2018/06/07 09:48:29 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int cnt;
	int sign;

	i = 0;
	cnt = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		cnt = cnt * 10 + ((int)str[i] - '0');
		i++;
	}
	if (sign == 1)
		return (-cnt);
	return (cnt);
}
