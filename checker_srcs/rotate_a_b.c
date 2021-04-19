/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:15:31 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/19 15:53:32 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_pile *a, char perm)
{
	t_nlist	*tmp;

	if (!a || !a->head || a->head == a->tail)
		return ;
	tmp = a->head;
	a->head = a->head->next;
	tmp->next = NULL;
	a->tail->next = tmp;
	a->tail = tmp;
	if (perm == 'y')
		ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_pile *b, char perm)
{
	t_nlist	*tmp;

	if (!b || !b->head || b->head == b->tail)
		return ;
	tmp = b->head;
	b->head = b->head->next;
	tmp->next = NULL;
	b->tail->next = tmp;
	b->tail = tmp;
	if (perm == 'y')
		ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_pile *a, t_pile *b, char perm)
{
	ft_ra(a, 'n');
	ft_rb(b, 'n');
	if (perm == 'y')
		ft_putstr_fd("rr\n", 1);
	return ;
}
