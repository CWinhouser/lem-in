/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:01:43 by ktwomey           #+#    #+#             */
/*   Updated: 2018/09/20 15:27:45 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdio.h>
# include "../includes/get_next_line/get_next_line.h"
# include "../includes/libft/libft.h"

typedef struct	s_maze
{
	int		antz;
	char	*start;
	char	*end;
	char	**map;
	char	**links;
}				t_maze;

typedef	struct	s_path
{
	char	**table;
	char	**stack_b;
}				t_path;

void	error(t_maze maze);
void	firstroom(char *str);
void	comparison(t_maze maze);
int		ft_findchar(char c, char *str);
t_maze	populate(t_path table, char *before, char after);
t_maze	ft_read(t_maze maze);
t_maze	ft_links(t_maze maze);
t_maze	init(t_maze maze);
t_maze	initcon(t_maze maze);
t_maze	ft_addline(char *line, t_maze maze);
t_maze	ft_start(t_maze maze);
t_maze	ft_end(t_maze maze);

#endif
