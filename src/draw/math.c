/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:11:34 by lpsyk             #+#    #+#             */
/*   Updated: 2022/10/27 08:59:26 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/draw.h"

float	ft_tangens(float degree)
{
	return (tan(((double) degree) * (M_PI) / 180.0));
}

float	ft_cosinus(float degree)
{
	return (cos(degree * ((float) M_PI) / 180.f));
}

float	ft_sinus(float degree)
{
	return (sinf(degree * ((float) M_PI) / 180.f));
}

t_position	ft_calc_grid_position(t_coordinate coord)
{
	return (ft_create_position((int) coord.x >> 6, (int) coord.y >> 6));
}

float	ft_calc_slope(t_coordinate origin, t_coordinate point)
{
	return ((point.y - origin.y) / (point.x - origin.x));
}
