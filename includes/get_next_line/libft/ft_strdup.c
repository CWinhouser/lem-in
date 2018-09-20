/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 08:40:38 by ktwomey           #+#    #+#             */
/*   Updated: 2018/06/30 13:56:54 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char *dup;

	dup = (char*)malloc(1 + ft_strlen((str)));
	if (!dup)
		return (NULL);
	dup = ft_strcpy(dup, (char*)str);
	return (dup);
}
