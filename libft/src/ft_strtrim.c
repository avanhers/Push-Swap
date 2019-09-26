/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:20:48 by avanhers          #+#    #+#             */
/*   Updated: 2019/04/06 14:32:09 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static int	nb_b(char const *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
	{
		i++;
		res++;
	}
	return (res);
}

static int	nb_a(char const *s)
{
	int	i;
	int	res;

	i = ft_strlen(s) - 1;
	res = 0;
	while ((s[i] == '\t' || s[i] == '\n' || s[i] == ' ') && i)
	{
		res++;
		i--;
	}
	return (res);
}

char		*ft_strtrim(char const *s)
{
	char		*res;
	size_t		len;

	if (s)
	{
		if ((size_t)nb_b(s) == ft_strlen(s))
		{
			res = (char*)malloc(sizeof(char));
			res[0] = '\0';
			return (res);
		}
		len = ft_strlen(s) - (nb_b(s) + nb_a(s));
		if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		res = ft_strsub(s, (unsigned int)nb_b(s), len);
		return (res);
	}
	else
		return (NULL);
}
