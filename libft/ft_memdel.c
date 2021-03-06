/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:32:45 by ibaran            #+#    #+#             */
/*   Updated: 2018/11/19 18:36:08 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <string.h>

void	*ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
	return (*ap);
}
