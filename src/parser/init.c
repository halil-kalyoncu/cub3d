/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:14:37 by lpsyk             #+#    #+#             */
/*   Updated: 2022/11/01 11:31:49 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static void	ft_load_image_door(t_data *data)
{
	int	width;
	int	height;

	data->image_door = mlx_xpm_file_to_image(data->mlx, PATH_DOOR, &width,
			&height);
	if (width != 64 || height != 64)
	{
		if (data->image_door != NULL)
			mlx_destroy_image(data->mlx, data->image_door);
		data->image_door = NULL;
	}
}

bool	ft_init_data(t_data *data)
{
	data->map = NULL;
	data->map_dimension = ft_create_position(0, 0);
	data->player_pos = ft_create_position(0, 0);
	data->player_angle = 0.f;
	data->win = NULL;
	data->image_northwall = NULL;
	data->image_eastwall = NULL;
	data->image_southwall = NULL;
	data->image_westwall = NULL;
	data->color_floor = ft_create_rgb(-1, -1, -1);
	data->color_ceiling = ft_create_rgb(-1, -1, -1);
	data->show_map = false;
	data->door_open = false;
	data->door_pos.x = 0;
	data->door_pos.y = 0;
	data->show_hands = false;
	data->mouse_turn = false;
	ft_load_image_door(data);
	return (data->image_door != NULL);
}

void	ft_init_infodata(t_infodata *infodata, void *mlxptr)
{
	infodata->map = NULL;
	infodata->image_northwall = NULL;
	infodata->image_eastwall = NULL;
	infodata->image_southwall = NULL;
	infodata->image_westwall = NULL;
	infodata->color_floor = ft_create_rgb(-1, -1, -1);
	infodata->color_ceiling = ft_create_rgb(-1, -1, -1);
	infodata->ready = READY_NOTCHECKED;
	infodata->mlx = mlxptr;
}

void	ft_free_infodata(t_infodata *infodata)
{
	if (infodata->image_northwall != NULL)
		mlx_destroy_image(infodata->mlx, infodata->image_northwall);
	if (infodata->image_eastwall != NULL)
		mlx_destroy_image(infodata->mlx, infodata->image_eastwall);
	if (infodata->image_southwall != NULL)
		mlx_destroy_image(infodata->mlx, infodata->image_southwall);
	if (infodata->image_westwall != NULL)
		mlx_destroy_image(infodata->mlx, infodata->image_westwall);
	ft_lstclear(&infodata->map, ft_free_lstcontent);
}

t_infoid	ft_identify_line(char *line, t_infodata *infodata)
{
	int	line_size;

	line_size = ft_strlen(line);
	if (infodata->ready != READY_CONTINUE)
	{
		if (line_size == 0)
			return (INFOID_EMPTY);
		if (line_size > 1 && ft_strncmp(line, "NO", 2) == 0)
			return (INFOID_NORTH);
		if (line_size > 1 && ft_strncmp(line, "EA", 2) == 0)
			return (INFOID_EAST);
		if (line_size > 1 && ft_strncmp(line, "SO", 2) == 0)
			return (INFOID_SOUTH);
		if (line_size > 1 && ft_strncmp(line, "WE", 2) == 0)
			return (INFOID_WEST);
		if (line[0] == 'F')
			return (INFOID_FLOOR);
		if (line[0] == 'C')
			return (INFOID_CEILING);
	}
	if (line_size == 0)
		return (INFOID_FAIL);
	if (ft_check_mapline(line) == true)
		return (INFOID_MAP);
	return (INFOID_FAIL);
}
