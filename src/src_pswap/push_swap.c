/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:21:46 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/06 16:39:16 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <unistd.h>

t_insert	find_best_elem(t_stack *stack_a, t_stack *stack_b)
{
	t_elem		*actual;
	t_insert	best;
	t_insert	tmp;
	int			i;

	i = 1;
	actual = stack_a->first;
	while (actual->nb == stack_a->max || actual->nb == stack_a->max1
			|| actual->nb == stack_a->max2)
		actual = actual->next;
	best = fill_insert(actual, stack_a, stack_b);
	actual = stack_a->first;
	while (i++ < stack_a->count)
	{
		actual = actual->next;
		tmp = fill_insert(actual, stack_a, stack_b);
		if (tmp.nb_op < best.nb_op && actual->nb != stack_a->max
				&& actual->nb != stack_a->max1 && actual->nb != stack_a->max2)
			best = tmp;
	}
	return (best);
}

int			count_rb(t_stack *stack_b)
{
	t_elem	*actual;
	int		res;

	actual = stack_b->first;
	res = 0;
	while (actual->nb != stack_b->max)
	{
		actual = actual->next;
		res++;
	}
	return (res);
}

void		insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_insert	insert;
	int			nb;

	while (stack_a->count > 3)
	{
		insert = find_best_elem(stack_a, stack_b);
		do_op(insert, stack_a, stack_b);
		if (!push(stack_b, stack_a))
			return ;
		write(1, "pb\n", 3);
	}
	nb = count_rb(stack_b);
	if (nb < (stack_b->count - nb) % stack_b->count)
		while (stack_b->first->nb != stack_b->max)
			do_print_rb(stack_b);
	else
		while (stack_b->first->nb != stack_b->max)
			do_print_rrb(stack_b);
	sort_three(stack_a);
	while (stack_b->first)
	{
		if (!push(stack_a, stack_b))
			return ;
		write(1, "pa\n", 3);
	}
}

void		launch_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->count > 3)
		find_max(stack_a);
	if (stack_a->count == 1)
		return ;
	else if (stack_a->count == 2)
		sort_two(stack_a);
	else if (stack_a->count == 3)
		sort_three(stack_a);
	else
		insertion_sort(stack_a, stack_b);
}

int			main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_mall	mall;

	mall.is_mall = 0;
	if (!rearrange(&argc, &argv, &mall))
		ft_exit(&mall, 0);
	if (argc == 0)
		return (EXIT_SUCCESS);
	if (!(check_arg(argc, argv)))
		ft_exit(&mall, 0);
	if (!(stack_a = fill_stack(argc, argv)))
		ft_exit(&mall, 0);
	mall.stack_a = stack_a;
	if (!(stack_b = init_empty_stack()))
		ft_exit(&mall, 1);
	mall.stack_b = stack_b;
	if (!check_double(stack_a))
		ft_exit(&mall, 2);
	if (is_sorted(stack_a, stack_b))
		ft_exit(&mall, 3);
	launch_sort(stack_a, stack_b);
	ft_exit(&mall, 3);
}
