/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:20:30 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/21 17:23:12 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_printf_listb(t_pile *b)
{
	t_pile	*b_c;
	t_nlist	*bb;

	b_c = ft_cpy_pile(b);
	bb = b_c->head;
	ft_printf("\n");
	while (bb && bb->next != NULL)
	{
		ft_printf("%s|b|		%d\n%s", RED, bb->nbr, NC);
		bb = bb->next;
	}
	ft_free_pile(b_c);
}

void	ft_printf_lista(t_pile *a)
{
	t_pile	*a_c;
	t_nlist	*aa;

	a_c = ft_cpy_pile(a);
	aa = a->head;
	while (aa && aa->next != NULL)
	{
		ft_printf("%s|a|		%d\n%s", GREEN, aa->nbr, NC);
		aa = aa->next;
	}
	ft_free_pile(a_c);
}

void	ft_print_piles(t_pile *a, t_pile *b, int perm)
{
	if (perm == 0)
		return ;
	ft_printf("\n****************************************\n");
	ft_printf_lista(a);
	ft_printf("%s|a|		%d%s\n", GREEN, a->tail->nbr, NC);
	if (b != NULL)
	{
		ft_printf_listb(b);
		ft_printf("%s|b|		%d%s\n", RED, b->tail->nbr, NC);
	}
	ft_printf("****************************************\n\n");
}
