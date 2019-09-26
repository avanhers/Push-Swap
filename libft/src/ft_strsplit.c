/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:57:39 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/06 15:47:07 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int		nb_word(char const *s, char c)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			res++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (res);
}

static int		s_wd(char const *s, char c, int i)
{
	int res;

	res = 0;
	while (s[i] != c && s[i] != '\0')
	{
		res++;
		i++;
	}
	return (res);
}

static char		*next_word(char const *s, char c, int *i)
{
	char	*res;
	int		k;

	if (!(res = (char*)malloc(sizeof(char) * (s_wd(s, c, *i) + 1))))
		return (NULL);
	k = 0;
	while (s[*i] != c && s[*i])
		res[k++] = s[(*i)++];
	res[k] = '\0';
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	if (s)
	{
		i = 0;
		if (!(res = (char**)malloc(sizeof(char*) * (nb_word(s, c) + 1))))
			return (NULL);
		j = 0;
		while (s[i] != '\0')
		{
			while (s[i] == c && s[i])
				i++;
			if (s[i])
				res[j++] = next_word(s, c, &i);
		}
		res[j] = 0;
		return (res);
	}
	else
		return (NULL);
}
