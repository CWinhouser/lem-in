/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:27:35 by ktwomey           #+#    #+#             */
/*   Updated: 2018/09/27 12:54:36 by ktwomey          ###   ########.fr       */
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
		path.a = ft_strsub(maze.links[maze.i], 0, ft_findchar('-', maze.links[maze.i]));
		after = ft_strsub(maze.links[maze.i],
				ft_findchar('-', maze.links[maze.i]) + 1, ft_strlen(maze.links[maze.i]));
		if (ft_strcmp(path.a, maze.start) == 0 || ft_strcmp(after, maze.start) == 0)
		{
			path = pathmaker(path, maze, after);
			path.table++;
		}
		maze.i++;
	}
	path = pathfill(path, maze);
	maze.i = 0;
	roomerror(path, maze);
}

t_path	pathmaker(t_path path, t_maze maze, char *b)
{
	char	*nexta;
	char	*nextb;
	
	maze.n = 0;
	path = newp(path, maze, b);
	while (maze.n < maze.count)
	{
		nexta = ft_strsub(maze.links[maze.n], 0, ft_findchar('-', maze.links[maze.n]));
		nextb = ft_strsub(maze.links[maze.n], ft_findchar('-', maze.links[maze.n]) + 1, 
				ft_strlen(maze.links[maze.n]));
		if ((ft_strcmp(path.a, nexta) == 0 && ft_strcmp(nexta, maze.start) != 0 &&
				ft_strcmp(nextb, maze.start) != 0))
			path = pathextension(path, maze, nextb, b);
		if (ft_strcmp(b, nexta) == 0 && ft_strcmp(nexta, maze.start) != 0 &&
				ft_strcmp(nextb, maze.start) != 0)
			path = pathextension(path, maze, nextb, b);
		if (ft_strcmp(path.a, nextb) == 0 && ft_strcmp(nexta, maze.start) != 0 &&
				ft_strcmp(nextb, maze.start) != 0)
			path = pathextension(path, maze, nexta, b);
		if (ft_strcmp(b, nextb) == 0 && ft_strcmp(nexta, maze.start) != 0 &&
				ft_strcmp(nextb, maze.start) != 0)
			path = pathextension(path, maze, nexta, b);
		maze.n++;
	}
	return (path);
}

t_path	pathextension(t_path path, t_maze maze, char *next, char *b)
{
	path.table++;
	path = newp(path, maze, b);
	path.path[path.table] = ft_strcat(path.path[path.table], "-");
	path.path[path.table] = ft_strjoin(path.path[path.table], next);
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
	int		end;

	maze.i = 0;
	while (maze.i < maze.count - 1)
	{
		end = 0;
		nexta = ft_strsub(maze.links[maze.i + 1], 0,
				ft_findchar('-', maze.links[maze.i + 1]));
		nextb = ft_strsub(maze.links[maze.i + 1], ft_findchar('-',
					maze.links[maze.i + 1]) + 1, ft_strlen(maze.links[maze.i + 1]));
		while (end < path.table)
		{
			pathend = ft_strrchr(path.path[end], '-') + 1;
			if (ft_strcmp(pathend, maze.end) == 0)
				break ;
			if (ft_strcmp(pathend, nexta) == 0)
				path = fill(path, nextb, end);
			if (ft_strcmp(pathend, nextb) == 0)
				path = fill(path, nexta, end);
			end++;
		}
		maze.i++;
	}
	return(path);
}
