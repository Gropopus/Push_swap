/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:11:11 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/18 16:06:28 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	ft_pa(t_pile *a, t_pile *b, char perm)
{
	t_nlist	*push;

	if (!b || !b->head)
		return ;
	push = b->head;
	b->head = push->next;
	if (!a->head)
	{
		push->next = NULL;
		a->head = push;
		a->tail = push;
	}
	else
	{
		push->next = a->head;
		a->head = push;
	}
	if (perm == 'y')
		ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_pile *a, t_pile *b, char perm)
{
	t_nlist	*push;

	if (!a || !a->head)
		return ;
	push = a->head;
	a->head = push->next;
	if (!b->head)
	{
		push->next = NULL;
		b->head = push;
		b->tail = push;
	}
	else
	{
		push->next = b->head;
		b->head = push;
	}
	if (perm == 'y')
		ft_putstr_fd("pb\n", 1);
}
