/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:58:44 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/16 12:39:07 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libc.h>
#include "libft.h"

static void		ft_itoanext(long int n, int len, char **str)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		len--;
		n = -n;
		**str = '-';
		i++;
	}
	while (len > 0)
	{
		*(*str + i) = (n / ft_power(10, len - 1)) + 48;
		n %= ft_power(10, len - 1);
		len--;
		i++;
	}
	*(*str + i) = '\0';
}

char			*ft_itoa(int n)
{
	int		len;
	int		num;
	char	*str;

	num = n;
	len = 0;
	if (num == 0)
	{
		str = (char*)malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	if (n < 0)
		len++;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_itoanext(n, len, &str);
	return (str);
}
