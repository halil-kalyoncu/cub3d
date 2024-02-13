/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpsyk <lpsyk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:23:54 by lpsyk             #+#    #+#             */
/*   Updated: 2022/11/01 10:18:25 by lpsyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/draw.h"

static t_coordinate	ft_change_coord(t_coordinate coord, float x_diff,
	float y_diff)
{
	t_coordinate	new_coord;

	new_coord.x = coord.x + x_diff;
	new_coord.y = coord.y + y_diff;
	return (new_coord);
}

static bool	ft_check_wall_collision(t_coordinate new_coord, char **map)
{
	t_coordinate	coord_up;
	t_coordinate	coord_right;
	t_coordinate	coord_down;
	t_coordinate	coord_left;

	coord_up = ft_create_coord(new_coord.x, new_coord.y - MOVE_SPEED);
	coord_right = ft_create_coord(new_coord.x + MOVE_SPEED, new_coord.y);
	coord_down = ft_create_coord(new_coord.x, new_coord.y + MOVE_SPEED);
	coord_left = ft_create_coord(new_coord.x - MOVE_SPEED, new_coord.y);
	return (ft_check_hit_wall(ft_calc_grid_position(coord_up), map)
		|| ft_check_hit_wall(ft_calc_grid_position(coord_right), map)
		|| ft_check_hit_wall(ft_calc_grid_position(coord_down), map)
		|| ft_check_hit_wall(ft_calc_grid_position(coord_left), map));
}

void	ft_move(int keycode, t_data *data)
{
	float			x_diff;
	float			y_diff;
	float			angle;
	t_coordinate	new_coord;

	angle = data->player_angle;
	if (keycode == KEY_D || keycode == KEY_A)
		angle -= 90.f;
	x_diff = ft_cosinus(angle) * MOVE_SPEED;
	y_diff = ft_sinus(angle) * MOVE_SPEED;
	if (keycode == KEY_S || keycode == KEY_A)
		x_diff *= (-1.f);
	if (keycode == KEY_W || keycode == KEY_D)
		y_diff *= (-1.f);
	new_coord = ft_change_coord(data->player_coord, x_diff, y_diff);
	if (ft_check_wall_collision(new_coord, data->map) == true)
		return ;
	if (data->door_open == true)
		ft_close_door(data->door_pos, data);
	data->player_coord = new_coord;
}
