/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:41:30 by ibaran            #+#    #+#             */
/*   Updated: 2018/12/14 11:41:43 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_FILLIT_H

# define H_FILLIT_H
# define BUFF_SIZE 22

# include "./libft/libft.h"
# include <libc.h>
# include <string.h>

typedef struct		s_tab
{
	char			sym;
	int				x;
	int				y;
	char			tab[4][4];
	struct s_tab	*next;
}					t_tab;

/*
** CHECK.C
*/
int					ft_check_input(char *input);
int					ft_tetrimino_is_valid(t_tab *current);

/*
** INSERT_AND_ORGANIZE
*/
void				ft_swap(t_tab **new, char r_or_c, int dest, int src);
int					ft_put_tetriminos_into_list(char *input, t_tab **first,
					int n);

/*
** ALLOC_AND_FREE
*/
int					ft_error(char **input, t_tab **first, int code);
void				fi_lstdel(t_tab **alst);
int					ft_free_tab(char ***tab, int to_return);
char				**reallocate(char ***pointer, int size);

/*
** GET_INPUT.c
*/
int					ft_getinput(const int fd, char **input);

/*
** SOLVE.C
*/
int					solve(t_tab *tab, int tetriminos, int color);

/*
** MOVE_AND_COPY
*/
void				ft_move_to_up_left(t_tab **new);
int					ft_move_right(char ***table, int x, int y, int size);
void				ft_copy_tmp_to_result(char ***result, char **tmp, int size);

/*
** PRINT_FILLIT
*/
void				ft_printfillit(char **array);

#endif
