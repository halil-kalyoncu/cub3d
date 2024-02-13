/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:24:24 by lpsyk             #+#    #+#             */
/*   Updated: 2022/10/27 09:23:10 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/draw.h"

static t_ray	ft_init_ray(t_data *data)
{
	t_ray	ray;

	ray.index = 0;
	ray.angle = data->player_angle + HFOV;
	ray.offset = FOV / ((float) PROJECTION_WIDTH);
	ray.fisheye_angle = HFOV;
	ray.image_northwall = data->image_northwall;
	ray.image_eastwall = data->image_eastwall;
	ray.image_southwall = data->image_southwall;
	ray.image_westwall = data->image_westwall;
	ray.image_door = data->image_door;
	return (ray);
}

static void	ft_move_ray(t_ray *ray)
{
	ray->angle -= ray->offset;
	ray->angle = ft_norm_angle(ray->angle);
	ray->fisheye_angle -= ray->offset;
	ray->index++;
}

void	ft_draw_projection(t_data *data)
{
	t_ray			ray;
	t_intersection	final_int;
	t_intersection	vertical_int;
	t_image			projection_image;
	t_image			texture_image;

	ray = ft_init_ray(data);
	projection_image = ft_create_projection_image(data->mlx, PROJECTION_WIDTH,
			PROJECTION_HEIGHT, data);
	mlx_put_image_to_window(data->mlx, data->win, projection_image.img, 0, 0);
	while (ray.index < PROJECTION_WIDTH)
	{
		final_int = ft_calc_horizontal_int(ray.angle, data);
		vertical_int = ft_calc_vertical_int(ray.angle, data);
		final_int = ft_compare_intersections(final_int, vertical_int, &ray,
				&texture_image);
		ft_draw_slice(ray.index, final_int, &projection_image, &texture_image);
		ft_move_ray(&ray);
	}
	mlx_put_image_to_window(data->mlx, data->win, projection_image.img, 0, 0);
	mlx_destroy_image(data->mlx, projection_image.img);
	ft_animate_hands(0, data);
}
