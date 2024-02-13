/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:13:19 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/10/31 09:14:50 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/draw.h"

static t_corner_id	ft_determine_cornerid(float ray_angle)
{
	bool	angle_facing_up;
	bool	angle_facing_right;

	angle_facing_up = ft_check_angle_facing_up(ray_angle);
	angle_facing_right = ft_check_angle_facing_right(ray_angle);
	if (angle_facing_up == true)
	{
		if (angle_facing_right == true)
			return (CORNER_UPRIGHT);
		else
			return (CORNER_UPLEFT);
	}
	if (angle_facing_right == true)
		return (CORNER_DOWNRIGHT);
	return (CORNER_DOWNLEFT);
}

static void	ft_adjust_neighbors(int x_diff, int y_diff,
	t_position *pos_neighbor1, t_position *pos_neighbor2)
{
	pos_neighbor1->x += x_diff;
	pos_neighbor2->y += y_diff;
}

bool	ft_check_horizontal_corner(t_coordinate coord, t_position pos,
	float ray_angle, char **map)
{
	t_corner_id	corner_id;
	float		tile_x;
	t_position	pos_neighbor1;
	t_position	pos_neighbor2;

	tile_x = fmod(coord.x, TILE_SIZE);
	corner_id = ft_determine_cornerid(ray_angle);
	pos_neighbor1 = pos;
	pos_neighbor2 = pos;
	if (corner_id == CORNER_UPLEFT && tile_x >= (TILE_SIZE - CORNER_PADDING))
		ft_adjust_neighbors(1, 1, &pos_neighbor1, &pos_neighbor2);
	else if (corner_id == CORNER_UPRIGHT && tile_x <= CORNER_PADDING)
		ft_adjust_neighbors((-1), 1, &pos_neighbor1, &pos_neighbor2);
	else if (corner_id == CORNER_DOWNRIGHT && tile_x <= CORNER_PADDING)
		ft_adjust_neighbors((-1), (-1), &pos_neighbor1, &pos_neighbor2);
	else if (corner_id == CORNER_DOWNLEFT
		&& tile_x <= (TILE_SIZE - CORNER_PADDING))
		ft_adjust_neighbors(1, (-1), &pos_neighbor1, &pos_neighbor2);
	return (ft_check_hit_wall(pos_neighbor1, map)
		&& ft_check_hit_wall(pos_neighbor2, map));
}

bool	ft_check_vertical_corner(t_coordinate coord, t_position pos,
	float ray_angle, char **map)
{
	t_corner_id	corner_id;
	float		tile_x;
	t_position	pos_neighbor1;
	t_position	pos_neighbor2;

	tile_x = fmod(coord.y, TILE_SIZE);
	corner_id = ft_determine_cornerid(ray_angle);
	pos_neighbor1 = pos;
	pos_neighbor2 = pos;
	if (corner_id == CORNER_UPLEFT && tile_x >= (TILE_SIZE - CORNER_PADDING))
		ft_adjust_neighbors(1, 1, &pos_neighbor1, &pos_neighbor2);
	else if (corner_id == CORNER_UPRIGHT
		&& tile_x >= (TILE_SIZE - CORNER_PADDING))
		ft_adjust_neighbors((-1), 1, &pos_neighbor1, &pos_neighbor2);
	else if (corner_id == CORNER_DOWNRIGHT && tile_x <= CORNER_PADDING)
		ft_adjust_neighbors((-1), (-1), &pos_neighbor1, &pos_neighbor2);
	else if (corner_id == CORNER_DOWNLEFT && tile_x <= CORNER_PADDING)
		ft_adjust_neighbors(1, (-1), &pos_neighbor1, &pos_neighbor2);
	return (ft_check_hit_wall(pos_neighbor1, map)
		&& ft_check_hit_wall(pos_neighbor2, map));
}
