/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:04:10 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/11/01 11:00:30 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static int	ft_found_empty_line(t_infodata *infodata, t_infoid infoid,
	char *line)
{
	return (true);
	(void) infodata;
	(void) infoid;
	ft_putstr_fd(line, STDERR_FILENO);
}

static void	ft_init_function_pointer(
	int (*process_line[9])(t_infodata *, t_infoid, char *))
{
	process_line[0] = &ft_found_empty_line;
	process_line[1] = &ft_set_texture;
	process_line[2] = &ft_set_texture;
	process_line[3] = &ft_set_texture;
	process_line[4] = &ft_set_texture;
	process_line[5] = &ft_set_color;
	process_line[6] = &ft_set_color;
	process_line[7] = &ft_add_mapline;
	process_line[8] = &ft_found_incorrect_line;
}

static bool	ft_check_file(t_infodata *infodata, int file_fd)
{
	char		*line;
	t_infoid	infoid;
	int			(*process_line[9])(t_infodata *, t_infoid, char *);

	ft_init_function_pointer(process_line);
	line = get_next_line(file_fd);
	while (line != NULL)
	{
		infoid = ft_identify_line(line, infodata);
		if ((*process_line[infoid])(infodata, infoid, line) == false)
		{
			free(line);
			return (false);
		}
		free(line);
		line = get_next_line(file_fd);
	}
	return (true);
}

static bool	ft_pass_to_data(t_data *data, t_infodata *infodata)
{
	ft_determine_map_dimensions(data, infodata->map);
	if (data->map_dimension.y < 3 || data->map_dimension.x < 3)
	{
		data->map_dimension.y = 0;
		data->map_dimension.x = 0;
		return (ft_write_error("Invalid map, too small"));
	}
	data->map = ft_init_map(infodata->map, data->map_dimension);
	if (data->map == NULL)
		return (ft_write_error("No space left on device"));
	data->image_northwall = infodata->image_northwall;
	data->image_eastwall = infodata->image_eastwall;
	data->image_southwall = infodata->image_southwall;
	data->image_westwall = infodata->image_westwall;
	data->color_floor = infodata->color_floor;
	data->color_ceiling = infodata->color_ceiling;
	return (true);
}

bool	ft_run_parser(t_data *data, const char *file_path)
{
	int			file_fd;
	t_infodata	infodata;

	if (ft_init_data(data) == false)
		return (ft_write_error("Couldn't open door texture file"));
	file_fd = open(file_path, O_RDONLY);
	if (file_fd == -1)
		return (ft_write_error("Couldn't open file"));
	ft_init_infodata(&infodata, data->mlx);
	if (ft_check_file(&infodata, file_fd) == false)
	{
		ft_free_infodata(&infodata);
		close(file_fd);
		return (false);
	}
	close(file_fd);
	if (ft_pass_to_data(data, &infodata) == false)
	{
		ft_free_infodata(&infodata);
		return (false);
	}
	ft_lstclear(&infodata.map, ft_free_lstcontent);
	if (ft_search_starting_pos(data) == false)
		return (false);
	return (ft_check_closed(data->map, data->map_dimension, data->player_pos));
}
