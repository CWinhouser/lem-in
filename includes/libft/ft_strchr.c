/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 09:03:07 by ktwomey           #+#    #+#             */
/*   Updated: 2018/06/04 09:56:52 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != (char)c)
	{
		i++;
	}
	if (str[i] != (char)c)
		return (NULL);
	return ((char *)&str[i]);
}
