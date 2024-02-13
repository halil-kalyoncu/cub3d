/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:32:18 by lpsyk             #+#    #+#             */
/*   Updated: 2022/11/01 11:31:30 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/draw.h"

float	ft_norm_angle(float angle)
{
	if (angle < 0.f)
		return (360.f + angle);
	if (angle >= 360.f)
		return (angle - 360.f);
	return (angle);
}

bool	ft_check_angle_facing_up(float angle)
{
	if (angle >= 0.f && angle < 180.f)
		return (true);
	return (false);
}

bool	ft_check_angle_facing_right(float angle)
{
	if ((angle >= 0.f && angle < 90.f) || angle >= 270.f)
		return (true);
	return (false);
}
