/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:07:02 by ktwomey           #+#    #+#             */
/*   Updated: 2018/06/18 10:01:24 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	char		*dst;
	const char	*sorc;
	size_t		cpylen;
	size_t		dlen;

	cpylen = dstsize;
	dst = (char *)dest;
	sorc = (const char *)src;
	while (cpylen-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - dest;
	cpylen = dstsize - dlen;
	if (cpylen == 0)
		return (dlen + ft_strlen(sorc));
	while (*sorc != '\0')
	{
		if (cpylen != 1)
		{
			*dst++ = *sorc;
			cpylen--;
		}
		sorc++;
	}
	*dst = '\0';
	return (dlen + (sorc - src));
}
