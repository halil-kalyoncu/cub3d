/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:15:38 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/04/05 11:20:14 by hkalyonc         ###   ########.fr       */
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

static	int	calc_size(int nb, int b)
{
	int	size;

	size = 0;
	while (nb != 0)
	{
		nb /= b;
		nb = ft_abs(nb);
		size++;
	}
	return (size);
}

static	char	*create_str(int nb, int b, char *base)
{
	char	*out;
	int		i;

	out = malloc(calc_size(nb, b) + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (nb != 0)
	{
		out[i++] = base[ft_abs(nb % b)];
		nb /= b;
		nb = ft_abs(nb);
	}
	out[i] = '\0';
	ft_strrev(&out);
	return (out);
}

char	*ft_itoa_base(int nb, char *base)
{
	char	*out;
	char	*tmp_out;
	int		b;

	if (ft_strlen(base) < 2)
		return (NULL);
	b = (int) ft_strlen(base);
	if (nb == 0)
		return (case_zero(base));
	else
		out = create_str(nb, b, base);
	if (nb < 0)
	{
		tmp_out = ft_strjoin("-", out);
		if (!tmp_out)
			return (NULL);
		free(out);
		return (tmp_out);
	}
	return (out);
}
