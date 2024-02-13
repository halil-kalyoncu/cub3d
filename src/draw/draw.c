/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:24:25 by lpsyk             #+#    #+#             */
/*   Updated: 2022/11/01 11:31:35 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/draw.h"

static int	ft_exit_event(t_data *data)
{
	ft_free_struct(data);
	exit(EXIT_SUCCESS);
	return (0);
}

static int	ft_update_window(t_data *data)
{
	ft_draw_projection(data);
	ft_draw_map(data);
	return (0);
}

static int	ft_key_event(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
		ft_move(keycode, data);
	else if (keycode == KEY_O && data->door_open == false)
		data->door_pos = ft_open_door(data);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		ft_turn(keycode, data);
	else if (keycode == KEY_ESC)
		ft_exit_event(data);
	else if (keycode == KEY_M)
		data->show_map = (data->show_map + 1) % 2;
	else if (keycode == KEY_H)
		data->show_hands = (data->show_hands + 1) % 2;
	else if (keycode == KEY_C)
		data->mouse_turn = (data->mouse_turn + 1) % 2;
	ft_update_window(data);
	return (0);
}

static void	ft_complete_data_struct(t_data *data)
{
	data->player_coord.x = ((float) data->player_pos.x) * TILE_SIZE
		+ TILE_SIZE / 2.f;
	data->player_coord.y = ((float) data->player_pos.y) * TILE_SIZE
		+ TILE_SIZE / 2.f;
	data->max_coord.x = ((float) data->map_dimension.x) * TILE_SIZE;
	data->max_coord.y = ((float) data->map_dimension.y) * TILE_SIZE;
}

void	ft_draw(t_data *data)
{
	data->win = mlx_new_window(data->mlx, PROJECTION_WIDTH,
			PROJECTION_HEIGHT, "CUB3D");
	ft_complete_data_struct(data);
	ft_update_window(data);
	mlx_loop_hook(data->mlx, ft_update_window, data);
	mlx_hook(data->win, 6, 1L << 0, ft_mouse_hook, data);
	mlx_hook(data->win, 2, (1L << 0), ft_key_event, data);
	mlx_hook(data->win, 17, (1L << 17), ft_exit_event, data);
	mlx_loop(data->mlx);
}
