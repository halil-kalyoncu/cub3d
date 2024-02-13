/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:07:25 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/04/05 11:22:07 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strc(char c, size_t size)
{
	char	*out;
	size_t	i;

	out = malloc(size + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (i < size)
	{
		out[i] = c;
		i++;
	}
	out[i] = '\0';
	return (out);
}
