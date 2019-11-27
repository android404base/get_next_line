/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydag <ydag@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 15:00:30 by ydag           #+#    #+#                */
/*   Updated: 2019/11/27 18:19:04 by ydag          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		*container[MAX_FD];
	char			*heap;
	int				check;

	if (!line || (fd < 0 || fd > MAX_FD) || (read(fd, container[fd], 0) < 0) \
		|| !(heap = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if (container[fd])
		if (check_line(&container[fd], line))
			return (1);
	check = read_file(fd, heap, &container[fd], line);
	free(heap);
	if (check != 0 || container[fd] == NULL || container[fd][0] == '\0')
	{
		if (!check && *line)
			*line = NULL;
		else if (check == 0)
			*line = ft_strdup("");
		return (check);
	}
	*line = container[fd];
	container[fd] = NULL;
	return (0);
}
