/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 09:27:23 by ktwomey           #+#    #+#             */
/*   Updated: 2018/09/29 14:25:39 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	compbefore(t_maze maze, t_path path)
{
	char	*temp;

	temp = ft_strsub(maze.links[maze.i], 0,
			ft_findchar('-', maze.links[maze.i]));
	path.a = temp;
	free(temp);
	return (path);
}

char	*set(t_maze maze)
{
	char	*temp;
	char	*val;

	temp = ft_strsub(maze.links[maze.i + 1], 0,
			ft_findchar('-', maze.links[maze.i + 1]));
	val = &(*temp);
	return (val);
}
