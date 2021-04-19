/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:35:47 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/18 14:42:24 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display_result(t_pile *a, t_pile *b)
{
	if ((ft_is_ok(a, b)) < 0)
		ft_printf("%sKO\n%s", RED, NC);
	else if (ft_is_ok(a, b) == 0)
		ft_printf("%sOK\n%s", GREEN, NC);
	ft_free_pile(a);
	ft_free_pile(b);
}
