/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <thsembel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:41:32 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/19 15:44:19 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_tab_len(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i] != NULL)
	{
		i++;
	}
	return (i);
}
