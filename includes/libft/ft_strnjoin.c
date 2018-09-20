/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:07:10 by ktwomey           #+#    #+#             */
/*   Updated: 2018/06/15 13:24:39 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *str1, char const *str2, size_t n)
{
	char	*ret;

	if (!str1 || !str2)
		return (NULL);
	ret = (char *)malloc(ft_strlen((char *)str1) + (n));
	if (!ret)
		return (NULL);
	ret = ft_strcpy(ret, str1);
	ret = ft_strncat(ret, str2, n);
	return (ret);
}
