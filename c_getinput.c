/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_getinput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:02:39 by ibaran            #+#    #+#             */
/*   Updated: 2018/12/13 16:33:25 by ibaran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_fillit.h"

int		input_memory_allocation(char **input, int new_size)
{
	char			*tmp;
	size_t			to_return;

	to_return = 0;
	if (!(*input))
	{
		if (!(*input = ft_strnew(new_size)))
			return (-1);
	}
	else
	{
		if (!(tmp = ft_strdup(*input)))
			return (-1);
		free(*input);
		to_return = ft_strlen(tmp);
		if (!(*input = ft_strnew(new_size + to_return)))
			return (-1);
		ft_strcpy(*input, tmp);
		free(tmp);
	}
	return ((int)to_return);
}

int		read_from_fd(const int fd, char *buffer, char **input)
{
	int		check_read;
	int		i;
	int		j;

	if (buffer)
		free(buffer);
	if (!(buffer = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	check_read = read(fd, buffer, BUFF_SIZE);
	if (check_read <= 0)
	{
		free(buffer);
		if (check_read == 0 && *input != NULL && ft_strlen(*input) != 0)
			return (0);
		return (-1);
	}
	buffer[check_read] = '\0';
	i = ft_strlen(buffer);
	if ((j = input_memory_allocation(input, i)) == -1)
		return (-1);
	ft_strncpy((*input) + j, buffer, i);
	return (read_from_fd(fd, buffer, input));
}

int		ft_getinput(const int fd, char **input)
{
	char	*buffer;

	buffer = NULL;
	return (read_from_fd(fd, buffer, input));
}
