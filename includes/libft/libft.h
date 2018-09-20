/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktwomey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 15:02:51 by ktwomey           #+#    #+#             */
/*   Updated: 2018/09/19 12:17:11 by ktwomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void	ft_putnbr(int i);
void	ft_putnbr_fd(int i, int fd);
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr(char const *str);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_memdel(void **del);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_memalloc(size_t n);
void	ft_strclr(char *str);
void	*ft_memccpy(void *dest, void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_striter(char *s, void (*f)(char*));
void	ft_striteri(char *str, void (*f)(unsigned int, char*));
void	ft_strdel(char **as);
int		ft_strequ(char const *str1, const char *str2);
int		ft_isalpha(int c);
int		ft_isdigit(int i);
int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(const char *str);
int		ft_tolower(int str);
int		ft_toupper(int str);
int		ft_intlen(int n);
int		ft_memcmp(const void *vo1, const void *vo2, size_t n);
int		ft_strcmp(const char *str1, const char *str2);
int		ft_strncmp(const char *str1, const char *str2, int n);
int		ft_strnequ(char const *str1, char const *str2, size_t n);
int		ft_isspace(int c);
char	*ft_strmapi(char const*str, char (*f)(unsigned int, char));
char	*ft_strmap(char const *str, char (*f)(char));
char	*ft_strnew(size_t n);
char	*ft_itoa(int n);
char	**ft_strsplit(char const *str, char c);
char	*ft_strcat(char *str1, const char *str2);
char	*ft_strncat(char *dest, const char *src, int n);
char	*ft_strchr(const char *str, int c);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t len);
char	*ft_strdup(const char *str);
char	*ft_strndup(const char *str, size_t n);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_strsub(char const *str, unsigned int start, size_t len);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strtrim(char const *str);
char	*ft_strnjoin(char const *str1, char const *str2, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);
#endif
