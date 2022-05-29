/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiski <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:40:54 by amiski            #+#    #+#             */
/*   Updated: 2022/04/16 20:15:51 by amiski           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"push_swap.h"

static char	*next_line(char **str)
{
	char	*freestr;
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	freestr = *str;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if (ft_strchr(*str, '\n'))
	{
		line = ft_substr(*str, 0, i + 1);
		*str = ft_strdup(*str + i + 1);
	}
	else
	{
		line = ft_strdup(*str);
		*str = NULL;
	}
	free(freestr);
	return (line);
}

static int	next_str(char **str, int fd)
{
	char	*buf;
	int		len;
	char	*freestr;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	if (read(fd, buf, 0) < 0)
	{
		free(buf);
		return (-1);
	}
	len = 1;
	while (!ft_strchr(*str, '\n') && len)
	{
		len = read(fd, buf, BUFFER_SIZE);
		buf[len] = '\0';
		freestr = *str;
		*str = ft_strjoin(*str, buf);
		free(freestr);
	}
	free(buf);
	return (len);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
		str = ft_strdup("");
	len = next_str(&str, fd);
	line = next_line(&str);
	if (len <= 0 && !line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
