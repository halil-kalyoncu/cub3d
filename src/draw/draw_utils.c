/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:42:38 by lpsyk             #+#    #+#             */
/*   Updated: 2022/10/27 08:07:48 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/draw.h"

t_position	ft_jump_to_first_pos(t_coordinate player_coord)
{
	t_position	pos;

	pos = ft_calc_grid_position(player_coord);
	pos.x -= 2;
	pos.y -= 2;
	return (pos);
}

void	ft_turn(int keycode, t_data *data)
{
	if (keycode == KEY_LEFT)
		data->player_angle += TURN_SPEED;
	else
		data->player_angle -= TURN_SPEED;
	data->player_angle = ft_norm_angle(data->player_angle);
}
