/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:21:19 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/04/09 09:31:18 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define NEWLINE_NOTFOUND -1
# define READ_FAILED -2
# define READ_LASTLINE -1
# include "../../libft/include/libft.h"
# include <sys/types.h>
# include <stdbool.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
void	ft_destroy_string(char **str);
int		ft_index_newline(char *str);
char	*ft_read_buffersize_characters(int fd);

#endif