/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:12:54 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/09/27 15:59:52 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_free_2d_array(void **array, size_t size_array)
{
	size_t	i;

	if (array == NULL)
		return ;
	i = 0;
	while (i < size_array)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
