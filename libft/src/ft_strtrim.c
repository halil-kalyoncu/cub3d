/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:11:23 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/04/05 11:23:06 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	int	check_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	void	calc_trimpoints(char const *s1, char const *set,
int *start, int *end)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && *start == i)
	{
		if (check_set(s1[i], set))
			(*start)++;
		i++;
	}
	i = (int) ft_strlen(s1) - 1;
	while (i > *start && *end == i)
	{
		if (check_set(s1[i], set))
			(*end)--;
		i--;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = (int) ft_strlen(s1) - 1;
	calc_trimpoints(s1, set, &start, &end);
	out = malloc(end - start + 2);
	if (!out)
		return (NULL);
	i = 0;
	while (start <= end)
		out[i++] = s1[start++];
	out[i] = '\0';
	return (out);
}
