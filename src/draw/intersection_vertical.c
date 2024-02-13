/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_vertical.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:30:23 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/10/27 09:22:26 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/draw.h"

static t_coordinate	ft_calc_first_vertical_intersection(
	t_coordinate player_coord, float ray_angle, float tan)
{
	t_coordinate	int_coord;

	int_coord.x = ((int) player_coord.x >> 6) << 6;
	if (ft_check_angle_facing_right(ray_angle) == true)
		int_coord.x += TILE_SIZE;
	else
		int_coord.x -= 0.0001f;
	int_coord.y = (player_coord.x - int_coord.x) * tan + player_coord.y;
	return (int_coord);
}

static t_coordinate	ft_calc_vertical_offset(float ray_angle, float tan)
{
	t_coordinate	offset;

	offset.x = TILE_SIZE;
	if (ft_check_angle_facing_right(ray_angle) == false)
		offset.x *= (-1.f);
	offset.y = (-1.0) * offset.x * tan;
	return (offset);
}

static bool	ft_check_vertical_wall_hit(t_coordinate coord, t_position pos,
	float ray_angle, char **map)
{
	if (ft_check_hit_wall(pos, map) == true)
		return (true);
	return (ft_check_vertical_corner(coord, pos, ray_angle, map));
}

static void	ft_find_vertical_int(float ray_angle, t_intersection *vertical_int,
	t_coordinate offset, t_data *data)
{
	int			depth_of_field;
	t_position	pos_int;

	depth_of_field = 0;
	if (ray_angle == 90.f || ray_angle == 270.f)
		depth_of_field = ft_look_up_bigger_grid(data->map_dimension);
	while (depth_of_field < ft_look_up_bigger_grid(data->map_dimension))
	{
		pos_int = ft_calc_grid_position(vertical_int->hit_coord);
		if (ft_check_pos_outside_map(pos_int, data->map_dimension) == true)
			break ;
		else if (ft_check_vertical_wall_hit(vertical_int->hit_coord, pos_int,
				ray_angle, data->map) == true)
		{
			vertical_int->hit_door = ft_check_hit_door(pos_int, data->map);
			vertical_int->distance = ft_calc_distance(data->player_coord,
					vertical_int->hit_coord);
			break ;
		}
		vertical_int->hit_coord.x += offset.x;
		vertical_int->hit_coord.y += offset.y;
		depth_of_field += 1;
	}
}

t_intersection	ft_calc_vertical_int(float ray_angle, t_data *data)
{
	t_intersection	vertical_int;
	float			tan;
	t_coordinate	offset;

	vertical_int.distance = ft_look_up_bigger_side(data->max_coord);
	tan = ft_tangens(ray_angle);
	vertical_int.hit_coord = ft_calc_first_vertical_intersection(
			data->player_coord, ray_angle, tan);
	offset = ft_calc_vertical_offset(ray_angle, tan);
	ft_find_vertical_int(ray_angle, &vertical_int, offset, data);
	vertical_int.texture_slice = ((int) vertical_int.hit_coord.y)
		% ((int) TILE_SIZE);
	return (vertical_int);
}
