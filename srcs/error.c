/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:37:33 by ktwomey           #+#    #+#             */
/*   Updated: 2018/09/27 12:46:44 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	roomerror(t_path path, t_maze maze)
{
	char	*room;
	char	**link;
	char	**test;
	int		*count;

	count = (int*)malloc(100);
	path.pathcount = (int*)malloc(sizeof(int) * 100);
	maze.i = 0;
	while (path.path[maze.i])
	{
		maze.n = 0;
		count[maze.i] = 0;
		test = ft_strsplit(path.path[maze.i], '-');
		path = pathcounter(path, test);
		while (maze.map[maze.n])
		{
			room = ft_strsub(maze.map[maze.n], 0, ft_findchar(' ', maze.map[maze.n]));
			count[maze.i] = count[maze.i] + strtestarray(test, room);
			maze.n++;
		}
		maze.i++;
	}
	finalpath(path, maze, count);
}

void	finalpath(t_path path, t_maze maze, int *count)
{
	int		store;
	int		temp;
	char	*first;
	char	*last;

	store = 0;
	maze.i = 0;
	while (count[maze.i])
	{
		first = ft_strsub(path.path[maze.i], 0, ft_findchar('-', path.path[maze.i]));
		last = ft_strrchr(path.path[maze.i], '-') + 1;
		if (count[maze.i] == path.pathcount[maze.i])
		{
			temp = count[maze.i];
			if (temp <= path.pathcount[maze.i] &&
					ft_strcmp(first, maze.start) == 0 &&
					ft_strcmp(last, maze.end) == 0)
				store = maze.i + 1;
		}
		maze.i++;
	}
	if (store == 0)
	{
		ft_putendl("No Path");
		exit(0);
	}
	printpath(path, maze, store);
}

t_path	pathcounter(t_path path, char **test)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (path.pathcount[n])
	{
		n++;
	}
	while (test[i])
		i++;
	path.pathcount[n] = i;
	return (path);
}

int		strtestarray(char **test, char *room)
{
	int		count;
	int		end;

	end = 0;
	count = 0;
	while (test[count])
	{
		if (ft_strcmp(test[count], room) == 0)
		{
			end++;
			return (end);
		}
		count++;
	}
	return (0);
}

void	ft_testline(char *line)
{
	char	**test;
	int		help;
	int		i;
	int		n;

	i = 0;
	test = ft_strsplit(ft_strchr(line, ' ') + 1, ' ');
	while (test[i])
	{
		n = 0;
		while (test[i][n])
		{
			if	(!(ft_isdigit(test[i][n])))
			{
				ft_putendl("Error");
				exit(0);
			}
			n++;
		}
		i++;
	}
}
