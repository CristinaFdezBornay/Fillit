/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:43:36 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/16 13:58:05 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printwordtab(char **array)
{
	while (*array != NULL)
	{
		ft_putstr(*array);
		ft_putchar('\n');
		array++;
	}
}