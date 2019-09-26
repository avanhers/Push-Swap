/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 07:49:50 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/06 16:05:15 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
#include "../inc/libft.h"

char		*ft_join_free(char *content, char *buf, int ret, int *len_content)
{
	char *res;

	res = (char*)malloc(sizeof(char) * (*len_content + ret + 1));
	if (res == NULL)
		return (0);
	ft_memcpy(res, content, *len_content);
	ft_memcpy(res + *len_content, buf, ret);
	res[*len_content + ret] = '\0';
	*len_content += ret;
	free(content);
	content = res;
	return (content);
}

static int	read_join(int fd, char **content, int *len_content)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;

	while ((*content == NULL || !ft_strchr(*content, '\n'))
			&& (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*content = ft_join_free(*content, buf, ret, len_content);
		if (*content == NULL)
			return (0);
	}
	return (1);
}

static int	actualize(char **line, char **content, int *i, int *len_content)
{
	*line = (char*)malloc(sizeof(char) * (++(*i) + 1));
	if (*line == NULL)
		return (0);
	(*line)[*i] = 0;
	ft_memcpy(*line, *content, *i);
	ft_memcpy(*content, *content + *i, *len_content - (*i - 1));
	*len_content -= *i;
	return (1);
}

int			free_static(char *content, int fd)
{
	if (fd == -1 && content)
	{
		free(content);
		return (1);
	}
	return (0);
}

int			get_next_line_wnl(const int fd, char **line)
{
	static char	*content = NULL;
	int			i;
	static int	len_content = 0;

	i = 0;
	if (free_static(content, fd))
		return (0);
	if (fd < 0 || line == NULL || read(fd, *line, 0) < 0)
		return (-1);
	if (!read_join(fd, &content, &len_content))
		return (-1);
	if (content)
		while (content[i] != '\n' && i < len_content)
			i++;
	if (!len_content)
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		free(content);
		return (0);
	}
	if (!actualize(line, &content, &i, &len_content))
		return (-1);
	return (1);
}
