/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsembel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:10:44 by thsembel          #+#    #+#             */
/*   Updated: 2021/04/19 15:45:23 by thsembel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] != NULL)
				free(str[i]);
			i++;
		}
		free(str);
		str = NULL;
	}
}
