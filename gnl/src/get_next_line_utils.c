/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:28:21 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/04/09 09:30:02 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

void	ft_destroy_string(char **str)
{
	free(*str);
	*str = NULL;
}

int	ft_index_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (NEWLINE_NOTFOUND);
}

char	*ft_read_buffersize_characters(int fd)
{
	char	*read_str;
	int		number_characters_read;

	read_str = malloc(BUFFER_SIZE + 1);
	if (!read_str)
		return (NULL);
	number_characters_read = read(fd, read_str, BUFFER_SIZE);
	if (number_characters_read < 0)
	{
		free(read_str);
		return (NULL);
	}
	read_str[number_characters_read] = '\0';
	return (read_str);
}
