/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:01:43 by ktwomey           #+#    #+#             */
/*   Updated: 2018/09/27 15:40:46 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdio.h>
# include <libc.h>
# include "../includes/get_next_line/get_next_line.h"
# include "../includes/libft/libft.h"

typedef struct	s_maze
{
	int			antz;
	char		*start;
	char		*end;
	char		**map;
	char		**links;
	int			i;
	int			n;
	int			count;
}				t_maze;

typedef	struct	s_path
{
	int			end;
	char		*a;
	char		**path;
	int			*pathcount;
	int			*count;
	int			table;
}				t_path;

t_maze			checkpath(t_maze maze, t_path path);
void			printerror(void);
void			error(t_maze maze);
void			firstroom(char *str);
void			comparison(t_maze maze);
int				ft_findchar(char c, char *str);
t_maze			populate(t_path table, char *before, char after);
t_maze			ft_read(t_maze maze);
t_maze			ft_links(t_maze maze);
t_maze			init(t_maze maze);
t_maze			initcon(t_maze maze);
t_maze			ft_addline(char *line, t_maze maze);
t_maze			ft_start(t_maze maze);
t_maze			ft_end(t_maze maze);
t_path			pathmaker(t_path path, t_maze maze, char *b);
t_path			pathfill(t_path path, t_maze maze);
t_path			newp(t_path path, t_maze maze, char *b);
t_path			pathextension(t_path path, t_maze maze, char *next, char *b);
t_path			fill(t_path path, char *next, int end);
void			roomerror(t_path path, t_maze maze);
void			ft_testline(char *line);
int				strtestarray(char **test, char *room);
t_path			pathcounter(t_path path, char **test);
void			finalpath(t_path path, t_maze maze, int *pathcount);
void			printpath(t_path path, t_maze maze, int store);
t_path			needed(t_path path, t_maze maze, char *nexta, char *b);

#endif
