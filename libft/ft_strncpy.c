/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:08:17 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/19 18:38:15 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*from;
	char	*to;

	from = (char*)src;
	to = dest;
	while (n != 0 && *from)
	{
		*to = *from;
		to++;
		from++;
		n--;
	}
	while (n != 0)
	{
		*to = '\0';
		to++;
		n--;
	}
	return (dest);
}
