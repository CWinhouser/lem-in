/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:49:29 by ktwomey           #+#    #+#             */
/*   Updated: 2018/06/11 15:00:43 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_fullstr(char const *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	if (*str != c)
		i = 1;
	j = 1;
	while (str[j])
	{
		if (str[j] != c && str[j - 1] == c)
			i++;
		j++;
	}
	return (i);
}

static int			ft_lenword(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

char				**ft_strsplit(char const *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	i = 0;
	k = 0;
	if (!(split = (char **)malloc(sizeof(split) *
						(ft_fullstr((char *)str, c)) + 1)) || !str)
		return (NULL);
	while (str[k] != '\0')
	{
		while (str[k] == c && str[k] != '\0')
			k++;
		if (str[k] == '\0')
			break ;
		split[i] = (char *)ft_strnew(ft_lenword((char *)&str[k], c));
		j = 0;
		while (str[k] != c && str[k] != '\0')
			split[i][j++] = str[k++];
		split[i][j] = '\0';
		i++;
	}
	split[i] = 0;
	return (split);
}
