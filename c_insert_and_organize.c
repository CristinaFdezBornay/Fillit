/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_insert_and_organize.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:02:44 by ibaran            #+#    #+#             */
/*   Updated: 2018/12/13 16:33:32 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fillit.h"

/*
** Putting tetriminos into chain list
*/

void	ft_swap(t_tab **new, char r_or_c, int dest, int src)
{
	int		m;
	char	tmp;

	m = -1;
	if (r_or_c == 'r')
		while (++m < 4)
		{
			tmp = (*new)->tab[dest][m];
			(*new)->tab[dest][m] = (*new)->tab[src][m];
			(*new)->tab[src][m] = tmp;
		}
	else
		while (++m < 4)
		{
			tmp = (*new)->tab[m][dest];
			(*new)->tab[m][dest] = (*new)->tab[m][src];
			(*new)->tab[m][src] = tmp;
		}
}

int		ft_insert_characters(t_tab **new, char *input, int n, int number)
{
	int		i;
	int		k;

	i = -1;
	while (++i < 4)
	{
		k = -1;
		while (++k < 4)
		{
			(*new)->tab[i][k] = '.';
			if (input[i * 5 + k] == '#')
			{
				(*new)->tab[i][k] = 'A' + n;
				number++;
			}
		}
	}
	(*new)->sym = 'A' + n;
	(*new)->x = 1;
	(*new)->y = 1;
	(*new)->next = NULL;
	if (number != 4 || ft_tetrimino_is_valid(*new) == -1)
		return (-1);
	ft_move_to_up_left(new);
	return (0);
}

int		ft_put_tetriminos_into_list(char *input, t_tab **first, int n)
{
	t_tab	*current;
	t_tab	*new;

	while (input[0] != '\0')
	{
		if (!(new = (t_tab*)malloc(sizeof(t_tab))) ||
		ft_insert_characters(&new, input, n, 0) == -1)
			return (ft_error(NULL, &new, 1));
		if (n == 0)
		{
			*first = new;
			current = *first;
		}
		else
		{
			current->next = new;
			current = current->next;
		}
		n++;
		if (input[19] == '\0' || input[20] == '\0')
			break ;
		input += 21;
	}
	return (n);
}
