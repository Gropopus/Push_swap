/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 17:58:25 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/19 15:52:25 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_error(t_pile *a, t_pile *b, t_inf *info)
{
	if (info)
	{
		free(info);
		info = NULL;
	}
	if (a && a->head)
		ft_free_pile(a);
	else
	{
		free(a);
		a = NULL;
	}
	if (b && b->head)
		ft_free_pile(b);
	else
	{
		free(b);
		b = NULL;
	}
	ft_putstr_fd("Error\n", 2);
	return (exit(1));
}
