/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:28:13 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/06 11:39:25 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	insert_min(t_insert insert, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = -1;
	if (insert.ra < insert.rra)
		while (++i < insert.ra)
			do_print_ra(stack_a);
	else
		while (++i < insert.rra)
			do_print_rra(stack_a);
	i = -1;
	if (insert.rb < insert.rrb)
		while (++i < insert.rb)
			do_print_rb(stack_b);
	else
		while (++i < insert.rrb)
			do_print_rrb(stack_b);
}

void	insert_rr(t_insert insert, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < ft_min(insert.ra, insert.rb))
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
		i++;
	}
	if (insert.ra > insert.rb)
		while (i++ < insert.ra)
			do_print_ra(stack_a);
	else
		while (i++ < insert.rb)
			do_print_rb(stack_b);
}

void	insert_rrr(t_insert *insert, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < ft_min(insert->rra, insert->rrb))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		write(1, "rrr\n", 4);
		i++;
	}
	if (insert->rra > insert->rrb)
		while (i++ < insert->rra)
			do_print_rra(stack_a);
	else
	{
		while (i++ < insert->rrb)
			do_print_rrb(stack_b);
	}
}

void	do_op(t_insert insert, t_stack *stack_a, t_stack *stack_b)
{
	if (insert.op == '1')
		insert_rr(insert, stack_a, stack_b);
	else if (insert.op == '2')
		insert_rrr(&insert, stack_a, stack_b);
	else
		insert_min(insert, stack_a, stack_b);
}
