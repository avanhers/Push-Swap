/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 16:55:09 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/06 16:23:08 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int			find_instruction(char *str, t_stack *stack_a, t_stack *stack_b)
{
	if (find_swap(str, stack_a, stack_b))
		return (1);
	else if (find_push(str, stack_a, stack_b))
		return (1);
	else if (find_rotate(str, stack_a, stack_b))
		return (1);
	else if (find_reverse_rotate(str, stack_a, stack_b))
		return (1);
	else
		return (0);
}

int			read_and_process(t_stack *stack_a, t_stack *stack_b)
{
	char *line;

	line = NULL;
	while (get_next_line_wnl(0, &line) > 0)
	{
		if (!find_instruction(line, stack_a, stack_b))
		{
			free(line);
			get_next_line_wnl(-1, &line);
			return (0);
		}
		free(line);
	}
	free(line);
	return (1);
}

void		checker(t_stack *stack_a, t_stack *stack_b, t_mall *mall)
{
	if (!read_and_process(stack_a, stack_b))
		ft_exit(mall, 2);
	if (is_sorted(stack_a, stack_b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int			main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_mall		mall;

	mall.is_mall = 0;
	if (!rearrange(&argc, &argv, &mall))
		ft_exit(&mall, 0);
	if (argc == 0)
		return (EXIT_SUCCESS);
	if (!check_arg(argc, argv))
		ft_exit(&mall, 0);
	if (!(stack_a = fill_stack(argc, argv)))
		ft_exit(&mall, 0);
	mall.stack_a = stack_a;
	if (!(stack_b = init_empty_stack()))
		ft_exit(&mall, 1);
	mall.stack_b = stack_b;
	if (!check_double(stack_a))
		ft_exit(&mall, 2);
	checker(stack_a, stack_b, &mall);
	ft_exit(&mall, 3);
}
