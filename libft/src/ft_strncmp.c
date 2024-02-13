/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:10:15 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/04/05 11:22:50 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		a;
	int		b;

	i = 0;
	a = 0;
	b = 0;
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
		{
			a = (unsigned char) s1[i];
			b = (unsigned char) s2[i];
			return (a - b);
		}
		i++;
	}
	if (s2[i] != '\0' && i < n)
	{
		a = (unsigned char) s2[i];
		return ((-1) * a);
	}
	return (0);
}
