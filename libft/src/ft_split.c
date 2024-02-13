/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 08:46:00 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/04/05 11:22:04 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	char	**free_out(char ***out, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free((*out)[i]);
		i++;
	}
	free(*out);
	return (NULL);
}

static	int	calc_splits(char const *s, char c)
{
	int	splits;
	int	i;

	splits = 0;
	i = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			splits++;
		i++;
	}
	return (splits);
}

static	char	*get_word(char const *s, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			break ;
		i++;
	}
	word = ft_substr(s, 0, i);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	int		i;

	if (!s)
		return (NULL);
	out = (char **) malloc((calc_splits(s, c) + 2) * sizeof(char *));
	if (!out)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			out[i] = get_word(s, c);
			if (!out[i])
				return (free_out(&out, i));
			s += (ft_strlen(out[i]));
			i++;
		}
		else
			s++;
	}
	out[i] = NULL;
	return (out);
}
