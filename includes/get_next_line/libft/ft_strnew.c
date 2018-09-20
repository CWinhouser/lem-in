/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 08:06:14 by ktwomey           #+#    #+#             */
/*   Updated: 2018/06/14 09:39:44 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t n)
{
	char *str;

	str = (char*)malloc(n * sizeof(char) + 1);
	if (!str)
		return (NULL);
	ft_bzero(str, n + 1);
	return (str);
}
