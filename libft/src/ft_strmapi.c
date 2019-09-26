/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:57:39 by avanhers          #+#    #+#             */
/*   Updated: 2019/04/06 14:28:14 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int i, char))
{
	char			*res;
	unsigned int	i;

	if (s != NULL)
	{
		if (!(res = (char*)malloc(sizeof(*res) * (ft_strlen(s) + 1))))
			return (NULL);
		i = 0;
		while (i < ft_strlen(s))
		{
			res[i] = f(i, s[i]);
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	else
		return (NULL);
}
