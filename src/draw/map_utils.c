/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:51:47 by lpsyk             #+#    #+#             */
/*   Updated: 2022/10/27 09:17:14 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/draw.h"

t_image	ft_create_transparent_image(void *mlx, int width, int height)
{
	t_image	img;
	int		x;
	int		y;

	img.img = mlx_new_image(mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			ft_mlx_pixel_put(&img, x, y, 0xFF000000);
			x++;
		}
		y++;
	}
	return (img);
}

bool	ft_check_pos_outside_map(t_position pos, t_position map_dimension)
{
	return (pos.x < 0 || pos.x >= map_dimension.x || pos.y < 0
		|| pos.y >= map_dimension.y);
}

int	ft_look_up_tile_color(t_position pos, t_data *data)
{
	if (ft_check_pos_outside_map(pos, data->map_dimension) == true)
		return (MAP_COLOROUTSIDE);
	else if (data->map[pos.y][pos.x] == '1')
		return (MAP_COLORWALL);
	else if (data->map[pos.y][pos.x] == '2')
		return (MAP_COLORDOORCLOSED);
	return (MAP_COLORFLOOR);
}
