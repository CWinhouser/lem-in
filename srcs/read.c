/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:06:55 by ktwomey           #+#    #+#             */
/*   Updated: 2018/09/29 14:34:35 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_maze		ft_addline(char *line, t_maze maze)
{
	int		i;
	int		error;

	error = 0;
	if (!(ft_findchar(' ', line)))
		return (maze);
	i = 0;
	if (line[0] != '#')
	{
		while (line[i])
		{
			if (line[i] == ' ')
				error++;
			i++;
		}
		if (error != 2)
			printerror();
	}
	i = 0;
	while (maze.map[i])
		i++;
	ft_testline(line);
	maze.map[i] = ft_strdup(line);
	return (maze);
}

t_maze		ft_read(t_maze maze)
{
	char	*line;
	int		ret;

	ret = 1;
	line = NULL;
	while (ret)
	{
		ret = get_next_line(0, &line);
		ft_putendl(line);
		maze.antz = ft_atoi(line);
		if (ft_intlen(maze.antz) == (int)ft_strlen(line))
		{
			free(line);
			return (maze);
		}
		free(line);
	}
	maze.antz = 0;
	return (maze);
}

t_maze		ft_start(t_maze maze)
{
	int		ret;
	int		i;

	i = 0;
	maze.line = NULL;
	ret = 1;
	while ((ret = get_next_line(0, &maze.line)))
	{
		ft_putendl(maze.line);
		maze = ft_addline(maze.line, maze);
		if (ft_strcmp(maze.line, "##start") == 0)
		{
			ret = get_next_line(0, &maze.line);
			if (ret)
			{
				ft_putendl(maze.line);
				maze = ft_addline(maze.line, maze);
				i = ft_findchar(' ', maze.line);
				maze.start = ft_strsub(maze.line, 0, i);
				return (maze);
			}
		}
	}
	maze.start = NULL;
	return (maze);
}

t_maze		ft_end(t_maze maze)
{
	int		ret;
	int		i;

	i = 0;
	ret = 1;
	maze.line = NULL;
	while ((ret = get_next_line(0, &maze.line)))
	{
		ft_putendl(maze.line);
		maze = ft_addline(maze.line, maze);
		if (ft_strcmp(maze.line, "##end") == 0)
		{
			ret = get_next_line(0, &maze.line);
			if (ret)
			{
				ft_putendl(maze.line);
				maze = ft_addline(maze.line, maze);
				i = ft_findchar(' ', maze.line);
				maze.end = ft_strsub(maze.line, 0, i);
				return (maze);
			}
		}
	}
	maze.start = NULL;
	return (maze);
}

t_maze		ft_links(t_maze maze)
{
	char	*line;
	int		ret;
	int		i;

	line = NULL;
	i = 0;
	while ((ret = get_next_line(0, &line)))
	{
		ft_putendl(line);
		if (ft_findchar('-', line))
			maze.links[i++] = ft_strdup(line);
		maze = ft_addline(line, maze);
		free(line);
	}
	if (i == 0)
		maze.links = NULL;
	return (maze);
}
