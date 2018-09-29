/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoext.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:42:47 by ktwomey           #+#    #+#             */
/*   Updated: 2018/09/29 14:34:53 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	fill(t_path path, char *next, int end)
{
	char	*temp;

	path.path[end] = ft_strcat(path.path[end], "-");
	temp = ft_strjoin(path.path[end], next);
	path.path[end] = temp;
	return (path);
}

t_path	needed(t_path path, t_maze maze, char *nexta, char *b)
{
	char	*nextb;

	nextb = ft_strrchr(maze.links[maze.i], '-');
	if (ft_strcmp(path.a, nexta) == 0 &&
			ft_strcmp(nexta, maze.start) != 0 &&
			ft_strcmp(nextb, maze.start) != 0)
		path = pathextension(path, maze, nextb, b);
	if (ft_strcmp(b, nexta) == 0 &&
			ft_strcmp(nexta, maze.start) != 0 &&
			ft_strcmp(nextb, maze.start) != 0)
		path = pathextension(path, maze, nextb, b);
	if (ft_strcmp(path.a, nextb) == 0 &&
			ft_strcmp(nexta, maze.start) != 0 &&
			ft_strcmp(nextb, maze.start) != 0)
		path = pathextension(path, maze, nexta, b);
	if (ft_strcmp(b, nextb) == 0 && ft_strcmp(nexta, maze.start) != 0 &&
			ft_strcmp(nextb, maze.start) != 0)
		path = pathextension(path, maze, nexta, b);
	return (path);
}

void	printerror(void)
{
	ft_putchar('\n');
	ft_putendl("Error");
	exit(0);
}

void	startend(t_maze maze)
{
	if (ft_strcmp(maze.start, maze.end) == 0)
	{
		ft_putchar('\n');
		ft_putendl("Start is end");
		exit(0);
	}
}
