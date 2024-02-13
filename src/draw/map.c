/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:02:26 by lpsyk             #+#    #+#             */
/*   Updated: 2022/10/27 08:58:48 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/draw.h"

void	ft_fill_map_tile(t_position pos, t_position map_pos, t_data *data,
	t_image *img)
{
	int			color;
	t_position	tile_pos;
	t_position	tile_coord;

	color = ft_look_up_tile_color(pos, data);
	tile_pos.y = 0;
	while (tile_pos.y < MAP_TILESIZE)
	{
		tile_pos.x = 0;
		while (tile_pos.x < MAP_TILESIZE)
		{
			tile_coord.x = (map_pos.x << 4) + tile_pos.x;
			tile_coord.y = (map_pos.y << 4) + tile_pos.y;
			if (tile_pos.x == 0 || tile_pos.y == 0)
				ft_mlx_pixel_put(img, tile_coord.x, tile_coord.y,
					MAP_COLORTILEEDGE);
			else
				ft_mlx_pixel_put(img, tile_coord.x, tile_coord.y, color);
			tile_pos.x++;
		}
		tile_pos.y++;
	}
}

void	ft_fill_map(t_data *data, t_image *img)
{
	t_position	pos;
	t_position	map_pos;

	pos = ft_jump_to_first_pos(data->player_coord);
	map_pos.y = 0;
	while (map_pos.y < MAP_HEIGHT)
	{
		map_pos.x = 0;
		while (map_pos.x < MAP_WIDTH)
		{
			ft_fill_map_tile(pos, map_pos, data, img);
			map_pos.x++;
			pos.x++;
		}
		pos.x -= MAP_WIDTH;
		map_pos.y++;
		pos.y++;
	}
}

static t_position	ft_create_player_map_coord(t_coordinate player_coord)
{
	t_position		player_mapcoord;
	t_coordinate	relativ_coord;
	int				offset_jump_to_middle;

	relativ_coord.x = player_coord.x / TILE_SIZE;
	relativ_coord.y = player_coord.y / TILE_SIZE;
	relativ_coord.x = relativ_coord.x - ((int) relativ_coord.x);
	relativ_coord.y = relativ_coord.y - ((int) relativ_coord.y);
	relativ_coord.x *= ((float) MAP_TILESIZE);
	relativ_coord.y *= ((float) MAP_TILESIZE);
	offset_jump_to_middle = 2 << 4;
	player_mapcoord.x = ((int) relativ_coord.x) + offset_jump_to_middle;
	player_mapcoord.y = ((int) relativ_coord.y) + offset_jump_to_middle;
	return (player_mapcoord);
}

static void	ft_fill_player(t_coordinate player_coord, t_image *img)
{
	t_position	player_mapcoord;
	int			x;
	int			y;

	player_mapcoord = ft_create_player_map_coord(player_coord);
	player_mapcoord.x -= 1;
	player_mapcoord.y -= 1;
	y = 0;
	while (y < 3)
	{
		x = 0;
		while (x < 3)
		{
			ft_mlx_pixel_put(img, player_mapcoord.x + x, player_mapcoord.y + y,
				MAP_COLORPLAYEREDGE);
			x++;
		}
		y++;
	}
	ft_mlx_pixel_put(img, player_mapcoord.x + 1, player_mapcoord.y + 1,
		MAP_COLORPLAYER);
}

void	ft_draw_map(t_data *data)
{
	t_image	img;

	if (data->show_map == false)
		return ;
	img.img = mlx_new_image(data->mlx, MAP_WIDTH * MAP_TILESIZE,
			MAP_HEIGHT * MAP_TILESIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	ft_fill_map(data, &img);
	ft_fill_player(data->player_coord, &img);
	mlx_put_image_to_window(data->mlx, data->win, img.img, MAP_OFFSETX,
		MAP_OFFSETY);
	mlx_destroy_image(data->mlx, img.img);
}
