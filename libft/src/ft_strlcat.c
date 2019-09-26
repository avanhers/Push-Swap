/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:18:26 by avanhers          #+#    #+#             */
/*   Updated: 2019/04/06 14:29:53 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l_dst;
	size_t	l_src;
	size_t	i;
	size_t	res;

	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	i = 0;
	while (*dst)
		dst++;
	if (size <= l_dst)
		return (size + l_src);
	else
	{
		while (src[i] && i < size - l_dst - 1)
		{
			dst[i] = src[i];
			i++;
		}
		res = l_dst + l_src;
		dst[i] = '\0';
	}
	return (res);
}
