/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:23:44 by lpsyk             #+#    #+#             */
/*   Updated: 2022/11/01 11:31:43 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static bool	ft_check_player_identifier(char c)
{
	return (c == 'N' || c == 'E' || c == 'S' || c == 'W');
}

static float	ft_map_angle(char direction)
{
	if (direction == 'N')
		return (90.f);
	if (direction == 'E')
		return (0.f);
	if (direction == 'S')
		return (270.f);
	return (180.f);
}

static bool	ft_check_current_position(int x, int y, t_data *data)
{
	if (y == 0 || x == 0 || y == data->map_dimension.y - 1
		|| x == data->map_dimension.x - 1)
	{
		return (ft_write_error("Invalid map, not surrounded by walls"));
	}
	if (data->player_pos.x != 0 && data->player_pos.y != 0)
	{
		return (ft_write_error("Only one starting pos allowed"));
	}
	data->player_pos = ft_create_position(x, y);
	data->player_angle = ft_map_angle(data->map[y][x]);
	data->map[y][x] = '0';
	return (true);
}

bool	ft_search_starting_pos(t_data *data)
{
	bool	found_starting_pos;
	int		x;
	int		y;

	y = 0;
	while (y < data->map_dimension.y)
	{
		x = 0;
		while (x < data->map_dimension.x)
		{
			if (ft_check_player_identifier(data->map[y][x]) == true)
			{
				if (ft_check_current_position(x, y, data) == false)
					return (false);
			}
			x++;
		}
		y++;
	}
	found_starting_pos = (data->player_pos.x != 0 && data->player_pos.y != 0);
	if (found_starting_pos == false)
		ft_write_error("Couldn't find player starting position");
	return (found_starting_pos);
}
