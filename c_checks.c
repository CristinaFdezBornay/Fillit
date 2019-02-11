/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_checks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:02:33 by ibaran            #+#    #+#             */
/*   Updated: 2018/12/13 16:33:19 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fillit.h"

/*
** Checking forbidden symbols, amount of lines and columns
*/

int		ft_check_input(char *input)
{
	int		i;
	int		columns;
	int		rows;

	i = 0;
	rows = 0;
	while (input[i] != '\0')
	{
		columns = 0;
		while (input[i] != '\n' && input[i] != '\0')
		{
			if (input[i] != '.' && input[i] != '#')
				return (-1);
			columns++;
			i++;
		}
		if (input[i++] == '\n')
			rows++;
		if ((columns != 4 && columns != 0) || (input[i] != '\0' &&
		input[i + 1] != '.' && input[i + 1] != '#' && input[i + 1] != '\0') ||
		((rows + 1) % 5 != 0 && input[i] == '\n' && input[i - 1] == '\n'))
			return (-1);
	}
	return ((rows + 1) % 5 == 0 ? 0 : -1);
}

/*
** Checking if all #'s are connected
** -2 is from out;
** -1 is from right (to left = k - 1)
**  0 is from left (to right = k + 1)
**  1 is from up (to down = i + 1)
*/

int		con(t_tab **curr, int i, int k, int from)
{
	int		to_r;

	to_r = 0;
	if ((i <= 3 && (k >= 0 && k <= 3)) && (*curr)->tab[i][k] != '.')
	{
		if (from == -2)
			to_r = 1 + con(curr, i, k + 1, 0) + con(curr, i + 1, k, 1);
		else if (from == -1)
			to_r = 1 + con(curr, i, k - 1, -1) + con(curr, i + 1, k, 1);
		else if (from == 0)
			to_r = 1 + con(curr, i, k + 1, 0) + con(curr, i + 1, k, 1);
		else if (from == 1)
			to_r = 1 + con(curr, i, k - 1, -1) + con(curr, i, k + 1, 0)
					+ con(curr, i + 1, k, 1);
		if (from == -1 || from == 0)
			(*curr)->x++;
		else if (from == 1)
			(*curr)->y++;
	}
	if (to_r == 6)
	{
		(*curr)->x = 2;
		(*curr)->y = 2;
	}
	return (to_r);
}

int		ft_tetrimino_is_valid(t_tab *current)
{
	int		n;
	int		i;
	int		k;
	int		to_return;

	to_return = 0;
	n = 0;
	i = -1;
	while (++i < 4)
	{
		k = -1;
		while (++k < 4)
			if (current->tab[i][k] != '.')
			{
				n++;
				break ;
			}
		if (n != 0)
			break ;
	}
	if (con(&current, i, k, -2) < 4)
		return (-1);
	return (to_return);
}
