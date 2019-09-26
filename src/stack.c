/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:26:28 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/06 13:59:18 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack		*fill_stack(int argc, char **argv)
{
	int			i;
	int			nb;
	t_stack		*stack;

	i = argc;
	stack = init_empty_stack();
	if (stack == NULL)
		return (NULL);
	while (--i >= 0)
	{
		nb = ft_atoi(argv[i]);
		if (!add_elem(stack, nb))
		{
			free_stack(stack);
			return (NULL);
		}
	}
	return (stack);
}

t_stack		*init_empty_stack(void)
{
	t_stack *stack;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	stack->first = NULL;
	stack->count = 0;
	stack->min = 2147483647;
	stack->max = -2147483648;
	return (stack);
}

int			check_double(t_stack *stack)
{
	t_elem *base;
	t_elem *actual;

	base = stack->first;
	while (base)
	{
		actual = base->next;
		while (actual)
		{
			if (actual->nb == base->nb)
				return (0);
			actual = actual->next;
		}
		base = base->next;
	}
	return (1);
}

void		print_stack(t_stack *stack)
{
	t_elem *actual;

	if (stack == NULL)
		return ;
	actual = stack->first;
	while (actual)
	{
		ft_putnbr(actual->nb);
		ft_putchar('\n');
		actual = actual->next;
	}
	ft_putchar('\n');
}

int			is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	t_elem *actual;

	if (!stack_a->first)
		return (0);
	actual = stack_a->first;
	while (actual->next)
	{
		if (actual->nb > actual->next->nb)
			return (0);
		actual = actual->next;
	}
	if (stack_b->first != NULL)
		return (0);
	return (1);
}
