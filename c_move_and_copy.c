/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_move_and_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:02:54 by ibaran            #+#    #+#             */
/*   Updated: 2018/12/13 16:33:43 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fillit.h"

void	ft_move_left(char ***table, int x, int size)
{
	int		i;
	int		k;

	k = -1;
	while (++k < x && size > x)
	{
		i = -1;
		while (++i < size && *(*(*table + i) + k + size - x) != '\0')
		{
			*(*(*table + i) + k) = *(*(*table + i) + k + size - x);
			*(*(*table + i) + k + size - x) = '.';
		}
	}
}

int		ft_move_down(char ***table, int x, int y, int size)
{
	int		i;
	int		k;

	k = -1;
	while (++k < size)
		if (*(*(*table + size - 1) + k) != '.')
			return (-1);
	ft_move_left(table, x, size);
	i = size;
	while (--i > 0 && y < size)
	{
		k = -1;
		while (++k < size)
		{
			*(*(*table + i) + k) = *(*(*table + i - 1) + k);
			*(*(*table + i - 1) + k) = '.';
		}
	}
	return (0);
}

int		ft_move_right(char ***table, int x, int y, int size)
{
	int		i;
	int		k;

	i = -1;
	while (++i < size)
		if (*(*(*table + i) + size - 1) != '.')
			return (ft_move_down(table, x, y, size));
	k = size;
	while (--k > 0 && x < size)
	{
		i = -1;
		while (++i < size)
		{
			*(*(*table + i) + k) = *(*(*table + i) + k - 1);
			*(*(*table + i) + k - 1) = '.';
		}
	}
	if (x >= size)
		return (ft_move_down(table, x, y, size));
	return (0);
}

void	ft_move_to_up_left(t_tab **new)
{
	int		i;
	int		k;
	int		empty;

	empty = 0;
	i = -1;
	while (++i < 4)
	{
		k = 0;
		while (k < 4 && (*new)->tab[i][k] == '.')
			k++;
		if (k != 4)
			ft_swap(new, 'r', empty++, i);
	}
	empty = 0;
	k = -1;
	while (++k < 4)
	{
		i = 0;
		while (i < 4 && (*new)->tab[i][k] == '.')
			i++;
		if (i != 4)
			ft_swap(new, 'c', empty++, k);
	}
}

void	ft_copy_tmp_to_result(char ***result, char **tmp, int size)
{
	int		i;
	int		k;

	i = -1;
	while (++i < size)
	{
		k = -1;
		while (++k < size)
			if (tmp[i][k] != '.')
				*(*(*result + i) + k) = tmp[i][k];
	}
}
