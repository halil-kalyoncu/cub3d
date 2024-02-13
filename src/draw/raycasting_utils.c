/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:34:33 by lpsyk             #+#    #+#             */
/*   Updated: 2022/10/27 09:26:47 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/draw.h"

float	ft_calc_distance(t_coordinate origin, t_coordinate hit)
{
	return (sqrtf((hit.x - origin.x) * (hit.x - origin.x) + (hit.y - origin.y)
			* (hit.y - origin.y)));
}

int	ft_calc_color_value(t_rgb rgb)
{
	return ((rgb.r << 16) + (rgb.g << 8) + rgb.b);
}

t_image	ft_create_projection_image(void *mlx, int width, int height,
					t_data *data)
{
	t_image	img;
	int		x;
	int		y;

	img.img = mlx_new_image(mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (y < (height >> 1))
				ft_mlx_pixel_put(&img, x, y,
					ft_calc_color_value(data->color_ceiling));
			else
				ft_mlx_pixel_put(&img, x, y,
					ft_calc_color_value(data->color_floor));
			x++;
		}
		y++;
	}
	return (img);
}

static	void	ft_init_slice_structs(t_intersection inter, t_slice_line *line,
	t_slice_texture *texture)
{
	line->height = (int) floorf(TILE_SIZE * ((float) PROJECTION_HEIGHT)
			/ inter.distance);
	if (line->height == 0)
		line->height = 1;
	texture->step = TILE_SIZE / ((float) line->height);
	texture->offset = 0;
	if (line->height > PROJECTION_HEIGHT)
	{
		texture->offset = (line->height - PROJECTION_HEIGHT) / 2;
		line->height = PROJECTION_HEIGHT;
	}
	line->offset = (PROJECTION_HEIGHT >> 1) - (line->height >> 1);
}

void	ft_draw_slice(int column, t_intersection inter, t_image *image,
	t_image *texture_image)
{
	t_slice_line	line;
	t_slice_texture	texture;
	int				y;
	float			ty;
	unsigned int	color;

	ft_init_slice_structs(inter, &line, &texture);
	y = 0;
	ty = texture.offset * texture.step;
	while (y < line.height)
	{
		color = ft_mlx_pixel_get(*texture_image, inter.texture_slice, ty);
		ft_mlx_pixel_put(image, column, line.offset + y, color);
		y++;
		ty += texture.step;
	}
}
