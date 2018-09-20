/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:27:35 by ktwomey           #+#    #+#             */
/*   Updated: 2018/09/20 15:27:42 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	comparison(t_maze maze)
{
	char	*after;
	char	*before;
	int		i;
	t_path	table;

	table.table = (char**)malloc(sizeof(char*) * 2000);
	i = 0;
	while (maze.links[i])
	{
		before = ft_strsub(maze.links[i], 0, ft_findchar('-', maze.links[i]));
		after = ft_strsub(maze.links[i], ft_findchar('-', maze.links[i]) + 1, ft_strlen(maze.links[i]));
		table = populate(table, before, after);
		i++;
	}
}

t_path	populate(t_path table, char *before, char *after)
{
	int	i;

	i = 0;
	while (table.table[i])
		i++;
	if (
