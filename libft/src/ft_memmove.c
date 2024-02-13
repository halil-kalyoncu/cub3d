/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:14:09 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/04/05 11:21:35 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	unsigned char	*ptr_re;

	if (!dest && !src)
		return (NULL);
	ptr_dest = (unsigned char *) dest;
	ptr_src = (unsigned char *) src;
	ptr_re = ptr_dest;
	if (ptr_src < ptr_dest)
	{
		ptr_src += (n - 1);
		ptr_dest += (n - 1);
		while (n--)
			*ptr_dest-- = *ptr_src--;
	}
	else
	{
		while (n--)
			*ptr_dest++ = *ptr_src++;
	}
	return (ptr_re);
}
