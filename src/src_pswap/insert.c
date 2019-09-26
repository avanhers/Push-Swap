/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:40:57 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/06 11:39:46 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int			nb_ra(t_elem *elem, t_stack *stack)
{
	t_elem	*actual;
	int		res;

	res = 0;
	actual = stack->first;
	while (actual != elem)
	{
		actual = actual->next;
		res++;
	}
	return (res);
}

void		rb_case_max(t_insert *insert, t_stack *stack_b)
{
	int		rb;
	t_elem	*actual;

	rb = 0;
	actual = stack_b->first;
	while (actual->nb != stack_b->max)
	{
		rb++;
		actual = actual->next;
	}
	insert->rb = rb;
}

void		nb_op(t_insert *insert)
{
	int		rarrb;
	int		rr;
	int		rrr;

	rarrb = ft_min(insert->ra, insert->rra) + ft_min(insert->rb, insert->rrb);
	rr = ft_max(insert->ra, insert->rb);
	rrr = ft_max(insert->rra, insert->rrb);
	insert->nb_op = ft_min(rarrb, rrr);
	insert->nb_op = ft_min(insert->nb_op, rr);
	if (insert->nb_op == rarrb)
		insert->op = '0';
	else if (insert->nb_op == rr)
		insert->op = '1';
	else
		insert->op = '2';
}

void		nb_rb(t_insert *insert, t_elem *elem, t_stack *stack_b)
{
	int				sup;
	int				rb;
	t_elem			*actual;
	int				count;

	sup = 2147483647;
	count = 0;
	actual = stack_b->first;
	rb = -1;
	if (!stack_b->first)
		return ;
	while (actual)
	{
		count++;
		if (actual->nb > elem->nb && actual->nb <= sup)
		{
			sup = actual->nb;
			rb = count;
		}
		actual = actual->next;
	}
	insert->rb = rb % stack_b->count;
	if (rb == -1)
		rb_case_max(insert, stack_b);
}

t_insert	fill_insert(t_elem *elem, t_stack *stack_a, t_stack *stack_b)
{
	t_insert insert;

	insert.ra = nb_ra(elem, stack_a);
	insert.rra = (stack_a->count - insert.ra) % stack_a->count;
	nb_rb(&insert, elem, stack_b);
	insert.rb = (stack_b->count == 0) ? 0 : insert.rb % stack_b->count;
	insert.rrb = (stack_b->count == 0) ? 0 : ((stack_b->count - insert.rb)
			% stack_b->count);
	nb_op(&insert);
	return (insert);
}
