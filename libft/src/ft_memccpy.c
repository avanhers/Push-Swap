/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:16:50 by avanhers          #+#    #+#             */
/*   Updated: 2019/04/04 18:30:21 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t						i;
	unsigned char				*res;
	const unsigned char			*source;

	i = 0;
	res = dst;
	source = src;
	while (i < n)
	{
		res[i] = source[i];
		dst++;
		if (source[i] == (unsigned char)c)
			return (dst);
		i++;
	}
	return (NULL);
}
