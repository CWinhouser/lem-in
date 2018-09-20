/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 09:08:00 by ktwomey           #+#    #+#             */
/*   Updated: 2018/06/07 09:49:59 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*source;
	unsigned char	stop;
	unsigned char	*ptr;

	ptr = 0;
	stop = (unsigned char)c;
	dst = (unsigned char *)dest;
	source = (unsigned char *)src;
	i = 0;
	while (i < n && ptr == 0)
	{
		dst[i] = source[i];
		if (source[i] == stop)
		{
			ptr = dst + i + 1;
		}
		i++;
	}
	return (ptr);
}
