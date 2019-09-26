/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:54:06 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/06 11:41:48 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_three(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->first->nb;
	second = stack_a->first->next->nb;
	third = stack_a->first->next->next->nb;
	if (first > second && second > third && first > third)
	{
		do_print_sa(stack_a);
		do_print_rra(stack_a);
	}
	else if (first < second && second > third && first < third)
	{
		do_print_rra(stack_a);
		do_print_sa(stack_a);
	}
	else if (first > second && second < third && first < third)
		do_print_sa(stack_a);
	else if (first < second && second > third && first > third)
		do_print_rra(stack_a);
	else if (first > second && second < third && first > third)
		do_print_ra(stack_a);
}

void	sort_two(t_stack *stack_a)
{
	if (stack_a->first->nb > stack_a->first->next->nb)
		do_print_sa(stack_a);
	return ;
}
