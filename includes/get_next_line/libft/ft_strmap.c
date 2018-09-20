/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 09:07:26 by ktwomey           #+#    #+#             */
/*   Updated: 2018/06/07 09:56:59 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
{
	int		i;
	char	*new;

	i = 0;
	if (!str || !f)
		return (NULL);
	new = (char*)malloc((ft_strlen((char*)str) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (str[i] != '\0')
	{
		new[i] = f((char)str[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
