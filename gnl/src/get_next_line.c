/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:20:54 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/09/26 09:56:04 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int	ft_check_fill_memory_end(char *read_str, char *memory)
{
	bool	found_nothing;
	bool	found_lastline;

	found_nothing = (ft_strlen(read_str) == 0 && ft_strlen(memory) == 0);
	found_lastline = (ft_strlen(read_str) == 0 && ft_strlen(memory) > 0);
	if (found_nothing)
		return (READ_FAILED);
	if (found_lastline)
		return (READ_LASTLINE);
	return (1);
}

int	ft_fill_memory_until_newline(int fd, char **memory)
{
	int		index_newline;
	char	*expanded_memory;
	char	*read_str;
	int		code_end;

	index_newline = ft_index_newline(*memory);
	if (index_newline != NEWLINE_NOTFOUND)
		return (index_newline);
	read_str = ft_read_buffersize_characters(fd);
	if (!read_str)
		return (READ_FAILED);
	code_end = ft_check_fill_memory_end(read_str, *memory);
	if (code_end < 0)
	{
		free(read_str);
		return (code_end);
	}
	expanded_memory = ft_strjoin(*memory, read_str);
	free(read_str);
	if (!expanded_memory)
		return (READ_FAILED);
	free(*memory);
	*memory = expanded_memory;
	return (ft_fill_memory_until_newline(fd, memory));
}

char	*ft_create_nextline(int index_newline, char *memory)
{
	char	*next_line;

	if (index_newline == READ_FAILED)
		return (NULL);
	if (index_newline == READ_LASTLINE)
		next_line = ft_substr(memory, 0, ft_strlen(memory));
	else
		next_line = ft_substr(memory, 0, index_newline);
	return (next_line);
}

bool	ft_update_memory(int index_newline, char **memory, char *next_line)
{
	char	*reduced_memory;

	if (index_newline == READ_FAILED || index_newline == READ_LASTLINE
		|| !next_line)
	{
		ft_destroy_string(memory);
		return (true);
	}
	reduced_memory = ft_substr(*memory, index_newline + 1, ft_strlen(*memory)
			- index_newline - 1);
	ft_destroy_string(memory);
	if (!reduced_memory)
		return (false);
	*memory = reduced_memory;
	return (true);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*memory;
	int			index_newline;
	bool		success_update_memory;

	if (fd < 0)
		return (NULL);
	if (!memory)
	{
		memory = ft_calloc(sizeof(char), 1);
		if (!memory)
			return (NULL);
	}
	index_newline = ft_fill_memory_until_newline(fd, &memory);
	next_line = ft_create_nextline(index_newline, memory);
	success_update_memory = ft_update_memory(index_newline, &memory, next_line);
	if (!success_update_memory)
	{
		free(next_line);
		return (NULL);
	}
	if (memory && memory[0] == '\0')
		ft_destroy_string(&memory);
	return (next_line);
}
