/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:02:49 by ibaran            #+#    #+#             */
/*   Updated: 2018/12/14 11:43:47 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fillit.h"

int		main(int ac, char *av[])
{
	int		fd;
	char	*input;
	t_tab	*tab;
	int		error_code;

	error_code = 0;
	if ((ac < 2 || ac > 3 || (ac == 3 && ft_strcmp(av[2], "-color") != 0)) ||
	((fd = open(av[1], O_RDONLY)) == -1) ||
	((error_code = 1 * ft_getinput(fd, &input)) == -1) ||
	((error_code = 2 * ft_check_input(input)) == -2) ||
	((error_code = 3 * ft_put_tetriminos_into_list(input, &tab, 0)) == -3) ||
	(error_code / 3 > 26 || error_code / 3 <= 0))
		return (ft_error(&input, &tab, error_code));
	if (ac == 3 && ft_strcmp(av[2], "-color") == 0)
		solve(tab, error_code / 3, 1);
	else
		solve(tab, error_code / 3, 0);
	fi_lstdel(&tab);
	free(input);
	return (0);
}
