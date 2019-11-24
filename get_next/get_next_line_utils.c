/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydag <ydag@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 14:56:45 by ydag           #+#    #+#                */
/*   Updated: 2019/11/21 19:42:31 by ydag          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		i;

	i = 0;
	while (s1[i])
		i += 1;
	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

char	*bring_them_all(char const *s1, char const *s2)
{
	char		*s3;
	char		*tmp_s3;
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	while (s1[i])
		i += 1;
	while (s2[j])
		j += 1;
	if (!s1 || !s2 || !(s3 = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	tmp_s3 = s3;
	while (*s1 != '\0')
		*tmp_s3++ = *s1++;
	while (*s2 != '\0')
		*tmp_s3++ = *s2++;
	*tmp_s3 = '\0';
	return (s3);
}

int		check_line(char **container, char **line)
{
	char	*tmp;
	char	*check_container;
	int		i;

	i = 0;
	check_container = *container;
	while (check_container[i] != '\n')
	{
		if (!check_container[i])
			return (0);
		i++;
	}
	tmp = &check_container[i];
	*tmp = '\0';
	*line = ft_strdup(*container);
	*container = ft_strdup(tmp + 1);
	return (1);
}

int		read_file(int fd, char *heap, char **container, char **line)
{
	char	*tmp;
	int		check;
	int		flag;

	flag = 1;
	while (flag && ((check = read(fd, heap, BUFFER_SIZE)) > 0))
	{
		heap[check] = '\0';
		if (*container)
		{
			tmp = *container;
			*container = bring_them_all(tmp, heap);
			free(tmp);
			tmp = NULL;
		}
		else
			*container = ft_strdup(heap);
		if (check_line(container, line))
			flag = 0;
	}
	return (check > 0 ? 1 : check);
}
