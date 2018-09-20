/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:07:04 by ktwomey           #+#    #+#             */
/*   Updated: 2018/06/11 08:32:24 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t n)
{
	void	*mal;

	mal = (void*)malloc(n);
	if (!mal)
		return (NULL);
	ft_bzero(mal, n);
	return (mal);
}
