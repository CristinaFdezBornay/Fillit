/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_printfillit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 10:22:39 by ibaran            #+#    #+#             */
/*   Updated: 2018/12/14 11:42:01 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fillit.h"
#include "h_colors.h"

void	ft_printfillit(char **array)
{
	int		i;
	int		k;
	int		index;

	i = 0;
	while (array[i] != NULL)
	{
		k = 0;
		while (array[i][k] != '\0')
		{
			index = 0;
			while (g_colors[index].sym != array[i][k])
				index++;
			ft_putstr(g_colors[index].code);
			ft_putstr("  ");
			ft_putstr(g_colors[0].code);
			k++;
		}
		ft_putendl("");
		i++;
	}
}
