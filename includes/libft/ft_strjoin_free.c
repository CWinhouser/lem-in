/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 13:15:28 by ktwomey           #+#    #+#             */
/*   Updated: 2018/09/29 13:20:24 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2, int i)
{
	char	*fresh;

	fresh = ft_strjoin(s1, s2);
	if (i == 1)
		free((void *)s1);
	else
		free((void *)s1);
	return (fresh);
}
