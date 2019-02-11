/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 10:18:26 by ibaran            #+#    #+#             */
/*   Updated: 2019/01/16 13:47:41 by crfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_COLORS_H

# define H_COLORS_H

typedef struct		s_color
{
	char	sym;
	char	code[20];
}					t_color;

t_color				g_colors[27] =
{
	{'.', "\033[39;49m"},
	{'A', "\033[48;5;160m"},
	{'B', "\033[48;5;41m"},
	{'C', "\033[48;5;163m"},
	{'D', "\033[48;5;21m"},
	{'E', "\033[48;5;166m"},
	{'F', "\033[48;5;37m"},
	{'G', "\033[48;5;136m"},
	{'H', "\033[48;5;28m"},
	{'I', "\033[48;5;174m"},
	{'J', "\033[48;5;69m"},
	{'K', "\033[48;5;212m"},
	{'L', "\033[48;5;214m"},
	{'M', "\033[48;5;72m"},
	{'N', "\033[48;5;39m"},
	{'O', "\033[48;5;222m"},
	{'P', "\033[48;5;61m"},
	{'Q', "\033[48;5;191m"},
	{'R', "\033[48;5;42m"},
	{'S', "\033[48;5;197m"},
	{'T', "\033[48;5;226m"},
	{'U', "\033[48;5;37m"},
	{'V', "\033[48;5;22m"},
	{'W', "\033[48;5;165m"},
	{'X', "\033[48;5;63m"},
	{'Y', "\033[48;5;166m"},
	{'Z', "\033[48;5;197m"}
};

#endif
