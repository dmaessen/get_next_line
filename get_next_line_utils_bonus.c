/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:51:12 by dmaessen          #+#    #+#             */
/*   Updated: 2023/02/07 18:26:23 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *memory, char *buf)
{
	size_t	i;
	size_t	len1;
	char	*join;

	if (!*memory && !*buf)
		return (free(memory), NULL);
	len1 = (ft_strlen(memory));
	join = ft_calloc((len1 + ft_strlen(buf) + 1), sizeof(char));
	if (!join)
		return (ft_free(&memory, NULL), NULL);
	i = 0;
	while (memory[i])
	{
		join[i] = memory[i];
		i++;
	}
	i = 0;
	while (buf[i])
	{
		join[len1 + i] = buf[i];
		i++;
	}
	join[len1 + ft_strlen(buf)] = '\0';
	return (free(memory), join);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = 0;
	while (s[i] && s[i + 1] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (&str[i + 1]);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)malloc (count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		sub = malloc(1 * sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
