/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:28:45 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/14 11:21:38 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <libc.h>

static int		len(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char		*ft_stage2(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*fr;
	char	*f_pointer;

	str1 = (char*)s1;
	str2 = (char*)s2;
	if (!(fr = (char*)malloc(sizeof(char) * (len(str1) + len(str2) + 1))))
		return (NULL);
	f_pointer = fr;
	while (*str1 != '\0')
	{
		*f_pointer = *str1;
		f_pointer++;
		str1++;
	}
	while (*str2 != '\0')
	{
		*f_pointer = *str2;
		f_pointer++;
		str2++;
	}
	*f_pointer = '\0';
	return (fr);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	if (s1 && s2)
		return (ft_stage2(s1, s2));
	else
		return (NULL);
}
