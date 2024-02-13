/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:08:42 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/04/05 11:23:23 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	void	rec_uitoa(char *str, unsigned int n, int *i)
{
	if (n < 10)
		str[(*i)++] = n + 48;
	else
	{
		rec_uitoa(str, n / 10, i);
		rec_uitoa(str, n % 10, i);
	}
}

char	*ft_uitoa(unsigned int n)
{
	char			*out;
	unsigned int	tmp;
	int				i;
	int				length;

	length = 2;
	tmp = n;
	while (tmp > 9)
	{
		length++;
		tmp /= 10;
	}
	out = malloc(length);
	if (!out)
		return (NULL);
	i = 0;
	rec_uitoa(out, n, &i);
	out[i] = '\0';
	return (out);
}
