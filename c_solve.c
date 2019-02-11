/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_solve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:03:00 by ibaran            #+#    #+#             */
/*   Updated: 2018/12/14 11:42:15 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fillit.h"

int		ft_check_pos(char **result, char **tmp, int size)
{
	int		i;
	int		k;

	i = -1;
	while (++i < size)
	{
		k = -1;
		while (++k < size)
			if (result[i][k] != '.' && tmp[i][k] != '.')
				return (-1);
	}
	return (0);
}

int		ft_clear_matrix(char ***result, t_tab *curr, int size)
{
	int		i;
	int		k;

	i = -1;
	while (++i < size)
	{
		k = -1;
		while (++k < size)
			if (*(*(*result + i) + k) == curr->sym)
				*(*(*result + i) + k) = '.';
	}
	return (-2);
}

int		ft_fill_matrix(char ***tmp, t_tab *curr)
{
	int		i;
	int		k;

	i = -1;
	while (++i < curr->y)
	{
		k = -1;
		while (++k < curr->x)
			*(*(*tmp + i) + k) = curr->tab[i][k];
	}
	return (-2);
}

int		main_recursivity(t_tab *curr, char ***result, int size, int to_return)
{
	char	**tmp;

	tmp = NULL;
	if (curr == NULL)
		return (0);
	if (curr->x > size || curr->y > size)
		return (-2);
	if ((tmp = reallocate(&tmp, size)) == NULL)
		return (-1);
	to_return = ft_fill_matrix(&tmp, curr);
	while (to_return == -2)
	{
		ft_clear_matrix(result, curr, size);
		while (ft_check_pos(*result, tmp, size) != 0)
			if (ft_move_right(&tmp, curr->x, curr->y, size) == -1)
				return (ft_free_tab(&tmp, to_return));
		ft_copy_tmp_to_result(result, tmp, size);
		if ((to_return = main_recursivity(curr->next, result, size, 0)) == -2)
			if (ft_move_right(&tmp, curr->x, curr->y, size) == -1)
			{
				ft_free_tab(&tmp, to_return);
				return (ft_clear_matrix(result, curr, size));
			}
	}
	return (ft_free_tab(&tmp, to_return));
}

int		solve(t_tab *first, int tetriminos, int color)
{
	char	**result;
	int		size;
	int		to_return;

	size = ft_sqrt(tetriminos * 4);
	result = NULL;
	if (!(result = reallocate(&result, size)))
		return (-1);
	while ((to_return = main_recursivity(first, &result, size, 0)) == -2)
	{
		size++;
		if (!(result = reallocate(&result, size)))
			return (-1);
	}
	if (color == 1 && to_return != -1)
		ft_printfillit(result);
	else if (to_return != -1)
		ft_printwordtab(result);
	else
		return (ft_error(NULL, &first, 1));
	return (ft_free_tab(&result, to_return));
}
