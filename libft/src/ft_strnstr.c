/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:10:43 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/04/05 11:22:54 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	tmp;
	size_t	j;

	if (!needle[0])
		return ((char *) haystack);
	i = 0;
	while (haystack[i] != '\0' && i < n)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			tmp = i;
			while (haystack[tmp] == needle[j]
				&& tmp < n && haystack[tmp] != '\0')
			{
				tmp++;
				j++;
				if (needle[j] == '\0')
					return ((char *) haystack + i);
			}
		}
		i++;
	}
	return (NULL);
}
