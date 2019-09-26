/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:24:56 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/06 13:42:27 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack *a)
{
	t_elem	*first;
	t_elem	*second;
	int		tmp;

	if (a->count <= 1)
		return ;
	else
	{
		first = a->first;
		second = first->next;
		tmp = first->nb;
		first->nb = second->nb;
		second->nb = tmp;
	}
}

int		push(t_stack *a, t_stack *b)
{
	if (b->count == 0)
		return (1);
	else if (!add_elem(a, remove_elem(b)))
		return (0);
	return (1);
}

void	rotate(t_stack *a)
{
	t_elem *first;
	t_elem *last;

	if (a->count <= 1)
		return ;
	last = a->first;
	while (last->next)
		last = last->next;
	first = a->first;
	a->first = a->first->next;
	first->next = NULL;
	last->next = first;
}

void	reverse_rotate(t_stack *a)
{
	t_elem *last;
	t_elem *new_last;

	if (a->count <= 1)
		return ;
	last = a->first;
	while (last->next)
	{
		if (!last->next->next)
			new_last = last;
		last = last->next;
	}
	new_last->next = NULL;
	last->next = a->first;
	a->first = last;
}
