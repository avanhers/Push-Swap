/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 10:46:38 by avanhers          #+#    #+#             */
/*   Updated: 2019/04/11 15:42:22 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void			remove_begin(t_list **begin, size_t s)
{
	t_list	*delete;

	if (*begin && (*begin)->content_size == s)
	{
		delete = *begin;
		*begin = (*begin)->next;
		free(delete->content);
		free(delete);
	}
}

static void			remove_elem(t_list **p, t_list **d, t_list **c)
{
	*d = *c;
	*c = (*c)->next;
	(*p)->next = *c;
	free((*d)->content);
	free(*d);
}

void				ft_lst_remove_if(t_list **begin_list, size_t s)
{
	t_list	*previous;
	t_list	*delete;
	t_list	*cpy;

	remove_begin(begin_list, s);
	if (*begin_list)
	{
		previous = *begin_list;
		cpy = previous->next;
		while (cpy)
		{
			while (cpy && cpy->content_size == s)
				remove_elem(&previous, &delete, &cpy);
			if (cpy)
			{
				previous = cpy;
				cpy = cpy->next;
			}
		}
	}
}
