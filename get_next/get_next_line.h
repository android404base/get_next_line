/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydag <ydag@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 14:59:23 by ydag           #+#    #+#                */
/*   Updated: 2019/12/04 18:14:48 by ydag          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# define MAX_FD 1024

int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
char	*bring_them_all(char const *s1, char const *s2);
int		check_line(char **container, char **line);
int		read_file(int fd, char *heap, char **container, char **line);
int		safe_out(int check, char *heap);

#endif
