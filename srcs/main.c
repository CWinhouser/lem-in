/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:05:31 by ktwomey           #+#    #+#             */
/*   Updated: 2018/09/29 14:25:37 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_maze	maze;
	int		i;

	i = 0;
	maze.map = (char**)malloc(sizeof(char) * 2000);
	maze.links = (char**)malloc(sizeof(char) * 2000);
	maze = init(maze);
	startend(maze);
	comparison(maze);
	exit(0);
}

int		ft_findchar(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

t_maze	init(t_maze maze)
{
	maze = ft_read(maze);
	if (maze.antz == 0)
	{
		ft_putchar('\n');
		ft_putendl("Error");
		exit(0);
	}
	maze = ft_start(maze);
	if (!maze.start)
	{
		ft_putchar('\n');
		ft_putendl("Error");
		exit(0);
	}
	maze = initcon(maze);
	return (maze);
}

t_maze	initcon(t_maze maze)
{
	maze = ft_end(maze);
	if (!maze.end)
	{
		ft_putchar('\n');
		ft_putendl("Error");
		exit(0);
	}
	maze = ft_links(maze);
	if (!maze.links)
	{
		ft_putchar('\n');
		ft_putendl("Error");
		exit(0);
	}
	return (maze);
}
