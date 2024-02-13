/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_horizontal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:30:18 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/10/27 09:20:58 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/draw.h"

static t_coordinate	ft_calc_first_horizontal_intersection(
	t_coordinate player_coord, float ray_angle, float co_tan)
{
	t_coordinate	int_coord;

	int_coord.y = ((int) player_coord.y >> 6) << 6;
	if (ft_check_angle_facing_up(ray_angle) == true)
		int_coord.y -= 0.0001f;
	else
		int_coord.y += TILE_SIZE;
	int_coord.x = (player_coord.y - int_coord.y) * co_tan + player_coord.x;
	return (int_coord);
}

static t_coordinate	ft_calc_horizontal_offset(float ray_angle, float co_tan)
{
	t_coordinate	offset;

	offset.y = TILE_SIZE;
	if (ft_check_angle_facing_up(ray_angle) == true)
		offset.y *= (-1.f);
	offset.x = (-1.f) * offset.y * co_tan;
	return (offset);
}

static bool	ft_check_horizontal_wall_hit(t_coordinate coord, t_position pos,
	float ray_angle, char **map)
{
	if (ft_check_hit_wall(pos, map) == true)
		return (true);
	return (ft_check_horizontal_corner(coord, pos, ray_angle, map));
}

static void	ft_find_horizontal_int(float ray_angle,
	t_intersection *horizontal_int, t_coordinate offset, t_data *data)
{
	int			depth_of_field;
	t_position	pos_int;

	depth_of_field = 0;
	if (ray_angle == 0.f || ray_angle == 180.f)
		depth_of_field = ft_look_up_bigger_grid(data->map_dimension);
	while (depth_of_field < ft_look_up_bigger_grid(data->map_dimension))
	{
		pos_int = ft_calc_grid_position(horizontal_int->hit_coord);
		if (ft_check_pos_outside_map(pos_int, data->map_dimension) == true)
			break ;
		else if (ft_check_horizontal_wall_hit(horizontal_int->hit_coord,
				pos_int, ray_angle, data->map) == true)
		{
			horizontal_int->hit_door = ft_check_hit_door(pos_int, data->map);
			horizontal_int->distance = ft_calc_distance(data->player_coord,
					horizontal_int->hit_coord);
			break ;
		}
		horizontal_int->hit_coord.x += offset.x;
		horizontal_int->hit_coord.y += offset.y;
		depth_of_field += 1;
	}
}

t_intersection	ft_calc_horizontal_int(float ray_angle, t_data *data)
{
	t_intersection	horizontal_int;
	float			co_tan;
	t_coordinate	offset;

	horizontal_int.distance = ft_look_up_bigger_side(data->max_coord);
	co_tan = 1.0 / ft_tangens(ray_angle);
	horizontal_int.hit_coord = ft_calc_first_horizontal_intersection(
			data->player_coord, ray_angle, co_tan);
	offset = ft_calc_horizontal_offset(ray_angle, co_tan);
	ft_find_horizontal_int(ray_angle, &horizontal_int, offset, data);
	horizontal_int.texture_slice = ((int) horizontal_int.hit_coord.x)
		% ((int) TILE_SIZE);
	return (horizontal_int);
}
