/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 08:47:22 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/11/01 08:49:47 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_position	ft_create_position(int x_value, int y_value)
{
	t_position	position;

	if (x_value < 0 || y_value < 0)
	{
		x_value = 0;
		y_value = 0;
	}
	position.x = x_value;
	position.y = y_value;
	return (position);
}

t_coordinate	ft_create_coord(float x_value, float y_value)
{
	t_coordinate	coord;

	if (x_value < 0.f || y_value < 0.f)
	{
		x_value = 0.f;
		y_value = 0.f;
	}
	coord.x = x_value;
	coord.y = y_value;
	return (coord);
}
