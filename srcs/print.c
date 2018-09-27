/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 11:55:58 by ktwomey           #+#    #+#             */
/*   Updated: 2018/09/27 15:03:03 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	printpath(t_path path, t_maze maze, int store)
{
	int		count;
	char	**split;

	split = ft_strsplit(path.path[store - 1], '-');
	while (maze.antz != 0)
	{
		count = 0;
		while (count != path.pathcount[store - 1])
		{
			ft_putchar('L');
			ft_putnbr(maze.antz);
			ft_putchar('-');
			ft_putstr(split[count]);
			ft_putchar('\n');
			count++;
		}
		maze.antz--;
	}
}
