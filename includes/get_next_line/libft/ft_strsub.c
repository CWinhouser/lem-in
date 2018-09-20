/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:27:00 by ktwomey           #+#    #+#             */
/*   Updated: 2018/06/11 13:25:28 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!str)
		return (NULL);
	new = (char *)ft_strnew(len);
	if (!new)
		return (NULL);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && str[start] != '\0')
	{
		*(new + i) = *(str + start);
		start++;
		i++;
	}
	return (new);
}
