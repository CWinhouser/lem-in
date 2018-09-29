/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:27:35 by ktwomey           #+#    #+#             */
/*   Updated: 2018/09/29 14:22:04 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	comparison(t_maze maze)
{
	char	*after;
	t_path	path;

	maze.count = 0;
	path.table = 0;
	path.path = (char**)malloc(sizeof(char) * 2000);
	while (maze.links[maze.count])
		maze.count++;
	maze.i = 0;
	while (maze.i < maze.count)
	{
		path = compbefore(maze, path);
		after = ft_strrchr(maze.links[maze.i], '-') + 1;
		if (ft_strcmp(path.a, maze.start) == 0 ||
				ft_strcmp(after, maze.start) == 0)
		{
			path = pathmaker(path, maze, after);
			path.table++;
		}
		maze.i++;
	}
	path = pathfill(path, maze);
	roomerror(path, maze);
}

t_path	pathmaker(t_path path, t_maze maze, char *b)
{
	char	*nexta;
	char	*temp;

	maze.n = 0;
	path = newp(path, maze, b);
	while (maze.n < maze.count)
	{
		temp = ft_strsub(maze.links[maze.n], 0,
				ft_findchar('-', maze.links[maze.n]));
		nexta = temp;
		path = needed(path, maze, nexta, b);
		maze.n++;
	}
	free(temp);
	return (path);
}

t_path	pathextension(t_path path, t_maze maze, char *next, char *b)
{
	char	*temp;

	path.table++;
	path = newp(path, maze, b);
	path.path[path.table] = ft_strcat(path.path[path.table], "-");
	temp = ft_strjoin_free(path.path[path.table], next, 1);
	path.path[path.table] = temp;
	return (path);
}

t_path	newp(t_path path, t_maze maze, char *b)
{
	path.path[path.table] = ft_strnew(100);
	if (ft_strcmp(path.a, maze.start) == 0)
	{
		path.path[path.table] = ft_strcat(path.path[path.table], path.a);
		path.path[path.table] = ft_strcat(path.path[path.table], "-");
		path.path[path.table] = ft_strcat(path.path[path.table], b);
	}
	if (ft_strcmp(b, maze.start) == 0)
	{
		path.path[path.table] = ft_strcat(path.path[path.table], b);
		path.path[path.table] = ft_strcat(path.path[path.table], "-");
		path.path[path.table] = ft_strcat(path.path[path.table], path.a);
	}
	return (path);
}

t_path	pathfill(t_path path, t_maze maze)
{
	char	*nexta;
	char	*nextb;
	char	*pathend;

	maze.i = 0;
	while (maze.i < maze.count - 1)
	{
		path.end = 0;
		nexta = set(maze);
		nextb = ft_strrchr(maze.links[maze.i + 1], '-');
		while (path.end < path.table)
		{
			pathend = ft_strrchr(path.path[path.end], '-') + 1;
			if (ft_strcmp(pathend, maze.end) == 0)
				break ;
			if (ft_strcmp(pathend, nexta) == 0)
				path = fill(path, nextb, path.end);
			if (ft_strcmp(pathend, nextb) == 0)
				path = fill(path, nexta, path.end);
			path.end++;
		}
		free(nexta);
		maze.i++;
	}
	return (path);
}
