/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:30:21 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/10/27 08:46:19 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/draw.h"

float	ft_look_up_bigger_side(t_coordinate max_coord)
{
	if (max_coord.x > max_coord.y)
		return (max_coord.x);
	return (max_coord.y);
}

int	ft_look_up_bigger_grid(t_position map_dimensions)
{
	if (map_dimensions.x > map_dimensions.y)
		return (map_dimensions.x);
	return (map_dimensions.y);
}

bool	ft_check_hit_wall(t_position pos, char **map)
{
	return (map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == '2');
}

bool	ft_check_hit_door(t_position pos, char **map)
{
	return (map[pos.y][pos.x] == '2');
}
