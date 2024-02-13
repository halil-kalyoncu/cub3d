/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:42:37 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/04/05 11:23:02 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_strrev(char **s)
{
	size_t	size;
	size_t	i;
	char	tmp;

	size = ft_strlen(*s);
	i = 0;
	while (i < size / 2)
	{
		tmp = (*s)[i];
		(*s)[i] = (*s)[size - 1 - i];
		(*s)[size - 1 - i] = tmp;
		i++;
	}
}
