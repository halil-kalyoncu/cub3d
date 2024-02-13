/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:38:30 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/10/27 09:19:32 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/draw.h"

static int	ft_flip_slice(int texture_slice)
{
	return (((int) TILE_SIZE) - 1 - texture_slice);
}

static t_intersection	ft_take_horizontal_int(t_intersection horizontal_int,
	t_ray *ray, t_image *texture_image)
{
	t_intersection	final_int;

	final_int = horizontal_int;
	if (ft_check_angle_facing_up(ray->angle) == true)
		texture_image->img = ray->image_northwall;
	else
	{
		texture_image->img = ray->image_southwall;
		final_int.texture_slice = ft_flip_slice(final_int.texture_slice);
	}
	return (final_int);
}

static t_intersection	ft_take_vertical_int(t_intersection vertical_int,
	t_ray *ray, t_image *texture_image)
{
	t_intersection	final_int;

	final_int = vertical_int;
	if (ft_check_angle_facing_right(ray->angle) == true)
		texture_image->img = ray->image_eastwall;
	else
	{
		texture_image->img = ray->image_westwall;
		final_int.texture_slice = ft_flip_slice(final_int.texture_slice);
	}
	return (final_int);
}

t_intersection	ft_compare_intersections(t_intersection horizontal_int,
	t_intersection vertical_int, t_ray *ray, t_image *texture_image)
{
	t_intersection	final_int;

	if (horizontal_int.distance < vertical_int.distance)
		final_int = ft_take_horizontal_int(horizontal_int, ray, texture_image);
	else
		final_int = ft_take_vertical_int(vertical_int, ray, texture_image);
	if (final_int.hit_door == true)
		texture_image->img = ray->image_door;
	texture_image->addr = mlx_get_data_addr(texture_image->img,
			&texture_image->bits_per_pixel, &texture_image->line_length,
			&texture_image->endian);
	final_int.distance *= ft_cosinus(ray->fisheye_angle);
	return (final_int);
}
