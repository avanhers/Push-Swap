/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:38:55 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/02 15:47:51 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdlib.h>

int	free_elem(int fd, t_list *elem)
{
	if (fd == -1 && elem != NULL)
	{
		free(elem->content);
		free(elem);
		return (1);
	}
	return (0);
}
