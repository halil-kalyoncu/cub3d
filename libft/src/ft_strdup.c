/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 09:49:54 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/04/05 11:22:15 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	char	*out;
	int		i;

	size = ft_strlen(s);
	out = malloc(size + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (i < size)
	{
		out[i] = s[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
