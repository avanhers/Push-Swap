/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:44:22 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/06 13:58:43 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int		find_swap(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (str == NULL)
		return (0);
	if (!ft_strcmp(str, "sa\n"))
	{
		swap(stack_a);
		return (1);
	}
	else if (!ft_strcmp(str, "sb\n"))
	{
		swap(stack_b);
		return (1);
	}
	else if (!ft_strcmp(str, "ss\n"))
	{
		swap(stack_a);
		swap(stack_b);
		return (1);
	}
	return (0);
}

int		find_push(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (str == NULL)
		return (0);
	if (!ft_strcmp(str, "pa\n"))
	{
		if (!push(stack_a, stack_b))
			return (0);
		return (1);
	}
	else if (!ft_strcmp(str, "pb\n"))
	{
		if (!push(stack_b, stack_a))
			return (0);
		return (1);
	}
	return (0);
}

int		find_rotate(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (str == NULL)
		return (0);
	if (!ft_strcmp(str, "ra\n"))
	{
		rotate(stack_a);
		return (1);
	}
	else if (!ft_strcmp(str, "rb\n"))
	{
		rotate(stack_b);
		return (1);
	}
	else if (!ft_strcmp(str, "rr\n"))
	{
		rotate(stack_a);
		rotate(stack_b);
		return (1);
	}
	return (0);
}

int		find_reverse_rotate(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (str == NULL)
		return (0);
	if (!ft_strcmp(str, "rra\n"))
	{
		reverse_rotate(stack_a);
		return (1);
	}
	else if (!ft_strcmp(str, "rrb\n"))
	{
		reverse_rotate(stack_b);
		return (1);
	}
	else if (!ft_strcmp(str, "rrr\n"))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		return (1);
	}
	return (0);
}
