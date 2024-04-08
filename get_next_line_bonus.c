/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkah-chu <lkah-chu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:45:27 by lkah-chu          #+#    #+#             */
/*   Updated: 2024/04/08 15:47:10 by lkah-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line_to_leftover(int fd, char *leftover_string)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(leftover_string, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		leftover_string = ft_strjoin(leftover_string, buffer);
	}
	free(buffer);
	return (leftover_string);
}

char	*get_next_line(int fd)
{
	char		*one_line;
	static char	*static_leftover_string[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_leftover_string[fd] = read_line_to_leftover(fd, static_leftover_string[fd]);
	if (!static_leftover_string[fd])
		return (NULL);
	one_line = get_one_line(static_leftover_string[fd]);
	static_leftover_string[fd] = get_leftover_string(static_leftover_string[fd]);
	return (one_line);
}
