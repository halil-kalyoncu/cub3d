/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:23:59 by lpsyk             #+#    #+#             */
/*   Updated: 2022/10/27 08:37:26 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/draw.h"

t_position	ft_open_door(t_data *data)
{
	float			x_diff;
	float			y_diff;
	t_coordinate	new_coord;
	t_position		new_pos;
	t_position		player_pos;

	x_diff = ft_cosinus(data->player_angle) * (MOVE_SPEED + MOVE_SPEED);
	y_diff = ft_sinus(data->player_angle) * (MOVE_SPEED + MOVE_SPEED);
	new_coord.x = data->player_coord.x + x_diff;
	new_coord.y = data->player_coord.y - y_diff;
	new_pos = ft_calc_grid_position(new_coord);
	if (ft_check_hit_door(new_pos, data->map) == true)
	{
		player_pos = ft_calc_grid_position(data->player_coord);
		data->map[new_pos.y][new_pos.x] = '0';
		data->door_open = true;
		data->door_pos = new_pos;
		data->player_coord = new_coord;
	}
	return (data->door_pos);
}

void	ft_close_door(t_position door_pos, t_data *data)
{
	t_position		player_pos;

	player_pos = ft_calc_grid_position(data->player_coord);
	if (player_pos.y != door_pos.y || player_pos.x != door_pos.x)
	{
		data->map[door_pos.y][door_pos.x] = '2';
		data->door_open = false;
	}
}
