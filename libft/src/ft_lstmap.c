/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avanhers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:05:12 by avanhers          #+#    #+#             */
/*   Updated: 2019/04/07 10:40:25 by avanhers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*next;
	t_list	*res;

	if (lst)
	{
		if (!(new = (t_list*)malloc(sizeof(t_list*))))
			return (NULL);
		new = f(lst);
		res = new;
		while (lst->next)
		{
			if (!(next = (t_list*)malloc(sizeof(t_list*))))
				return (NULL);
			new->next = f(lst->next);
			new = new->next;
			lst = lst->next;
		}
		new->next = NULL;
		return (res);
	}
	return (NULL);
}
