/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:06:54 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/19 15:25:18 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_sa(t_pile *a, char perm)
{
	int		tmp;

	if (!a || a->head == NULL || a->head->next == NULL)
		return ;
	tmp = a->head->nbr;
	a->head->nbr = a->head->next->nbr;
	a->head->next->nbr = tmp;
	if (perm == 'y')
		ft_putstr_fd("sa\n", 1);
}

void		ft_sb(t_pile *b, char perm)
{
	int	tmp;

	if (!b || b->head == NULL || b->head->next == NULL)
		return ;
	tmp = b->head->nbr;
	b->head->nbr = b->head->next->nbr;
	b->head->next->nbr = tmp;
	if (perm == 'y')
		ft_putstr_fd("sb\n", 1);
}

void		ft_ss(t_pile *a, t_pile *b, char perm)
{
	if (a && b)
	{
		ft_sa(a, 'n');
		ft_sb(b, 'n');
	}
	if (perm == 'y')
		ft_putstr_fd("ss\n", 1);
}
