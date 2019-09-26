/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:42:43 by avanhers          #+#    #+#             */
/*   Updated: 2019/08/06 16:26:28 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_min(int a, int b)
{
	return (a < b ? a : b);
}

int		ft_max(int a, int b)
{
	return (a > b ? a : b);
}

void	find_max(t_stack *a)
{
	t_elem	*act;

	a->max = -2147483648;
	a->max1 = -2147483648;
	a->max2 = -2147483648;
	act = a->first;
	while (act)
	{
		a->max = (act->nb > a->max) ? act->nb : a->max;
		act = act->next;
	}
	act = a->first;
	while (act)
	{
		if (act->nb > a->max1 && act->nb != a->max)
			a->max1 = act->nb;
		act = act->next;
	}
	act = a->first;
	while (act)
	{
		if (act->nb > a->max2 && act->nb != a->max && act->nb != a->max1)
			a->max2 = act->nb;
		act = act->next;
	}
}

int		count_nb_word(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int		rearrange(int *argc, char ***argv, t_mall *mall)
{
	int i;

	i = 0;
	if (*argc == 2)
	{
		if (!(*argv = ft_strsplit((*argv)[1], ' ')))
			return (0);
		*argc = count_nb_word(*argv);
		mall->is_mall = 1;
		mall->argv = *argv;
	}
	else
	{
		while (i < *argc - 1)
		{
			(*argv)[i] = (*argv)[i + 1];
			i++;
		}
		(*argv)[i] = 0;
		(*argc)--;
	}
	return (1);
}
