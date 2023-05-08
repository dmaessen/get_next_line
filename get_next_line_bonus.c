/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:48:38 by dmaessen          #+#    #+#             */
/*   Updated: 2023/02/09 12:56:03 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(char **memory, char *line)
{
	free(*memory);
	*memory = NULL;
	free(line);
}

static char	*current_line(char *memory)
{
	size_t	i;
	char	*line;

	i = 0;
	while (memory[i] != '\0' && memory[i] != '\n')
		i++;
	if (memory[i] == '\n')
		i++;
	line = ft_substr(memory, 0, i);
	if (!line)
		return (free(line), NULL);
	return (line);
}

static char	*sub_mem(char *memory)
{
	size_t	i;
	size_t	len;
	char	*sub;

	i = 0;
	len = ft_strlen(memory);
	while (memory[i] != '\0' && memory[i] != '\n')
		i++;
	if (memory[i] == '\n')
		i++;
	if (!memory[i])
		return (free(memory), NULL);
	sub = ft_substr(memory, i, len - i);
	if (!sub)
		return (ft_free(&memory, NULL), NULL);
	free(memory);
	return (sub);
}

static char	*reading(int fd, char *memory)
{
	int		nbyte;
	char	*buf;

	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (free(memory), NULL);
	nbyte = 1;
	while (nbyte != 0 && !ft_strchr(memory, '\n'))
	{
		nbyte = read(fd, buf, BUFFER_SIZE);
		if (nbyte < 0)
			return (ft_free(&memory, buf), NULL);
		buf[nbyte] = '\0';
		memory = ft_strjoin(memory, buf);
		if (!memory)
			return (ft_free(&memory, buf), NULL);
	}
	free (buf);
	return (memory);
}

char	*get_next_line(int fd)
{
	static char	*memory[OPEN_MAX];
	char		*newline;

	if (fd < 0 || fd >= OPEN_MAX
		|| BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	if (!memory[fd])
	{
		memory[fd] = ft_calloc(1, 1);
		if (!memory[fd])
			return (NULL);
	}
	memory[fd] = reading(fd, memory[fd]);
	if (!memory[fd])
		return (ft_free(&memory[fd], NULL), NULL);
	newline = current_line(memory[fd]);
	if (!newline)
		return (ft_free(&memory[fd], NULL), NULL);
	memory[fd] = sub_mem(memory[fd]);
	return (newline);
}
