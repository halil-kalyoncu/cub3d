/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:15:34 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/04/08 16:22:20 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putstr_lowercase(int fd, const char *str)
{
	char	character_to_write;
	int		conversion_to_lowercase;
	int		i;

	if (!(fd == STDOUT_FILENO || fd == STDERR_FILENO))
		return ;
	i = 0;
	conversion_to_lowercase = 'a' - 'A';
	while (str[i])
	{
		character_to_write = str[i];
		if (ft_islowercase(str[i]))
			character_to_write += conversion_to_lowercase;
		write(fd, &character_to_write, 1);
		i++;
	}
}
