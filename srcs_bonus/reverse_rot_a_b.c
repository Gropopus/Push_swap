/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rot_a_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:20:25 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/19 15:33:32 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra(t_pile *a, char perm)
{
	t_nlist	*tmp;

	if (!a || !a->head || a->head == a->tail)
		return ;
	tmp = a->head;
	while (tmp->next != a->tail)
		tmp = tmp->next;
	tmp->next->next = a->head;
	a->head = tmp->next;
	tmp->next = NULL;
	a->tail = tmp;
	if (perm == 'y')
		ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_pile *b, char perm)
{
	t_nlist	*tmp;

	if (!b || !b->head || b->head == b->tail)
		return ;
	tmp = b->head;
	while (tmp->next != b->tail)
		tmp = tmp->next;
	tmp->next->next = b->head;
	b->head = tmp->next;
	tmp->next = NULL;
	b->tail = tmp;
	if (perm == 'y')
		ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_pile *a, t_pile *b, char perm)
{
	if (a && b)
	{
		ft_rra(a, 'n');
		ft_rrb(b, 'n');
	}
	if (perm == 'y')
		ft_putstr_fd("rrr\n", 1);
	return ;
}
