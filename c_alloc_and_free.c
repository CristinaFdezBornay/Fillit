/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_alloc_and_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:02:25 by ibaran            #+#    #+#             */
/*   Updated: 2018/12/13 16:34:52 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fillit.h"

int		ft_error(char **input, t_tab **first, int code)
{
	if (input && *input)
		free(*input);
	fi_lstdel(first);
	if (code != 0)
		ft_putstr("error\n");
	else
		ft_putstr("usage: ./fillit <valid path> [-color]\n");
	exit(0);
}

void	fi_lstdel(t_tab **alst)
{
	t_tab		*rem_next;

	if (!alst)
		return ;
	rem_next = (*alst);
	while (rem_next != NULL)
	{
		*alst = rem_next;
		rem_next = (*alst)->next;
		free(*alst);
		*alst = NULL;
	}
}

int		ft_free_tab(char ***pointer, int to_return)
{
	int		i;

	i = 0;
	if (*pointer != NULL)
	{
		while (*(*pointer + i) != NULL)
		{
			free(*(*pointer + i));
			i++;
		}
		free(*pointer);
	}
	return (to_return);
}

char	*ft_newrow(size_t size)
{
	char	*str;
	char	*pointer;

	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	pointer = str;
	while (size != 0)
	{
		*pointer = '.';
		pointer++;
		size--;
	}
	*pointer = '\0';
	return (str);
}

char	**reallocate(char ***pointer, int size)
{
	char	**result;
	int		i;

	ft_free_tab(pointer, 0);
	result = *pointer;
	if (!(result = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	result[size] = NULL;
	i = -1;
	while (++i < size)
		if (!(result[i] = ft_newrow(size)))
			return (NULL);
	return (result);
}
