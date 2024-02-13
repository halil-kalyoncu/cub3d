/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:15:38 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/04/05 11:23:20 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	char	*case_zero(char *base)
{
	char	*out;

	out = malloc(2);
	if (!out)
		return (NULL);
	out[0] = base[0];
	out[1] = '\0';
	return (out);
}

static	int	calc_size(unsigned int nb, int b)
{
	int	size;

	size = 0;
	while (nb != 0)
	{
		nb /= b;
		size++;
	}
	return (size);
}

static	char	*create_str(unsigned int nb, int b, char *base)
{
	char	*out;
	int		i;

	out = malloc(calc_size(nb, b) + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (nb != 0)
	{
		out[i++] = base[nb % b];
		nb /= b;
	}
	out[i] = '\0';
	ft_strrev(&out);
	return (out);
}

char	*ft_uitoa_base(unsigned int nb, char *base)
{
	char			*out;
	unsigned int	b;

	if (ft_strlen(base) < 2)
		return (NULL);
	b = (unsigned int) ft_strlen(base);
	if (nb == 0)
		return (case_zero(base));
	else
		out = create_str(nb, b, base);
	return (out);
}
