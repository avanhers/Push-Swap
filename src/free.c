/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 10:52:33 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/06 16:37:26 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		free_arg(char **argv)
{
	int i;

	i = -1;
	while (argv[++i])
		free(argv[i]);
	free(argv);
}

void		free_stack(t_stack *stack)
{
	t_elem	*actual;
	t_elem	*next;

	while (stack && stack->first)
	{
		actual = stack->first;
		next = stack->first;
		while (next->next)
		{
			actual = next;
			next = next->next;
		}
		if (actual == next)
		{
			free(stack->first);
			stack->first = NULL;
		}
		else
		{
			actual->next = NULL;
			free(next);
		}
	}
	free(stack);
}

void		ft_exit(t_mall *mall, int n)
{
	if (mall->is_mall == 1)
		free_arg(mall->argv);
	if (n >= 1)
		free_stack(mall->stack_a);
	if (n >= 2)
		free_stack(mall->stack_b);
	if (n <= 2)
		ft_error("Error");
	if (n > 2)
		exit(EXIT_SUCCESS);
}
