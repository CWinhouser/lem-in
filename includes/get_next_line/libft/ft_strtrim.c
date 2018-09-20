/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 08:52:51 by ktwomey           #+#    #+#             */
/*   Updated: 2018/06/12 13:54:00 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*start;
	char	*end;
	char	*ret;
	char	*new;

	if (!s)
		return (NULL);
	start = (char *)s;
	while (*start == '\t' || *start == ' ' || *start == '\n')
		start++;
	end = (char *)s + ft_strlen(s) - 1;
	while ((*end == '\t' || *end == ' ' || *end == '\n') && end >= start)
		end--;
	if (!(ret = malloc(end - start + 2)))
		return (NULL);
	new = ret;
	while (start <= end)
		*new++ = *start++;
	*new = 0;
	return (ret);
}
