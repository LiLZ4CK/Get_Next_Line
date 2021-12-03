/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:37:33 by zwalad            #+#    #+#             */
/*   Updated: 2021/12/03 13:43:47 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*get_line(char *str)
{
	int		i;
	int		j;
	char	*l;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		l = ft_substr(str, 0, i + 1);
		free(str);
		str = NULL;
		return (l);
	}
	l = ft_strdup(str);
	free(str);
	str = NULL;
	return (l);
}

char	*get_next(char *str)
{
	int		i;
	char	*sstr;

	i = 0;
	sstr = NULL;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		i++;
		sstr = ft_substr(str, i, ft_strlen(str) - i);
	}
	return (sstr);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*str;
	char		*line;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (len > 0 && !ft_strchr(str))
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[len] = '\0';
		str = ft_strjoin(str, buf);
		if (len <= 0)
			break ;
	}
	free(buf);
	if (!str[0])
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	line = get_line(str);
	str = get_next(str);
	return (line);
}
