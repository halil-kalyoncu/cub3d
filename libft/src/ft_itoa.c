/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:08:42 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/04/05 11:20:17 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	int	calc_length(int n)
{
	int	length;

	length = 2;
	if (n < 0)
	{
		length++;
		n *= (-1);
	}
	while (n > 9)
	{
		length++;
		n /= 10;
	}
	return (length);
}

static	void	rec_itoa(char *str, int n, int *i)
{
	if (n < 10)
		str[(*i)++] = n + 48;
	else
	{
		rec_itoa(str, n / 10, i);
		rec_itoa(str, n % 10, i);
	}
}

char	*ft_itoa(int n)
{
	char	*out;
	int		negative;
	int		i;

	if (n == -2147483648)
	{
		out = ft_strdup("-2147483648");
		return (out);
	}
	out = malloc(calc_length(n));
	if (!out)
		return (NULL);
	negative = 0;
	if (n < 0)
	{
		negative = 1;
		n *= -1;
	}
	i = 0;
	if (negative)
		out[i++] = '-';
	rec_itoa(out, n, &i);
	out[i] = '\0';
	return (out);
}
