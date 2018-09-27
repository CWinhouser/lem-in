/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoext.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:42:47 by ktwomey           #+#    #+#             */
/*   Updated: 2018/09/26 15:01:39 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	fill(t_path path, char *next, int end)
{
	path.path[end] = ft_strcat(path.path[end], "-");
	path.path[end] = ft_strjoin(path.path[end], next);
	return (path);
}
