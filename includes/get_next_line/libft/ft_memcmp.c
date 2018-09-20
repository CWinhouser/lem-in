/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 08:59:54 by ktwomey           #+#    #+#             */
/*   Updated: 2018/06/01 15:00:12 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *vo1, const void *vo2, size_t n)
{
	if (!n)
	{
		return (0);
	}
	while (--n && *(char *)vo1 == *(char *)vo2)
	{
		vo1 = (char *)vo1 + 1;
		vo2 = (char *)vo2 + 1;
	}
	if ((char *)vo1 == (char *)vo2)
		return (0);
	else
		return (*((unsigned char *)vo1) - *((unsigned char *)vo2));
}
