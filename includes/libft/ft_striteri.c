/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 07:53:24 by ktwomey           #+#    #+#             */
/*   Updated: 2018/05/31 07:55:37 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	unsigned int i;

	i = 0;
	if (!str || !f)
		return ;
	while (str[i] != '\0')
	{
		f(i, &str[i]);
		i++;
	}
}
