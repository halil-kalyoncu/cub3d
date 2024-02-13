/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:28:09 by lpsyk             #+#    #+#             */
/*   Updated: 2022/10/31 14:35:47 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static bool	ft_check_color_line(char **line_splitted, t_infoid infoid)
{
	bool	check_identifier;

	if (line_splitted[0] == NULL || line_splitted[1] == NULL
		|| line_splitted[2] != NULL)
		return (false);
	if (ft_strlen(line_splitted[0]) != 1)
		return (false);
	if (infoid == INFOID_FLOOR)
		check_identifier = ft_strncmp(line_splitted[0], "F", 1) == 0;
	else
		check_identifier = ft_strncmp(line_splitted[0], "C", 1) == 0;
	if (check_identifier == false)
		return (false);
	return (ft_check_rgb_str(line_splitted[1]));
}

static bool	ft_extract_color(char *rgb_str, t_rgb *color)
{
	char	**values;

	values = ft_split(rgb_str, ',');
	if (values == NULL)
		return (ft_write_error("No space left on device"));
	if (values[0] == NULL || values[1] == NULL || values[2] == NULL
		|| values[3] != NULL)
	{
		ft_free_2d_array_nullterminated((void **) values);
		return (ft_write_error("Something unexpected happend"));
	}
	*color = ft_create_rgb(ft_atoi(values[0]), ft_atoi(values[1]),
			ft_atoi(values[2]));
	ft_free_2d_array_nullterminated((void **) values);
	if (color->r == -1)
		return (ft_write_error("RGB Values have to be between 0 and 255"));
	return (true);
}

bool	ft_read_color(char *line, t_infoid infoid, t_rgb *color)
{
	bool	success_read_color;
	char	**line_splitted;

	*color = ft_create_rgb(-1, -1, -1);
	if (ft_strchr(line, '\t') != NULL)
		return (ft_write_error("Tab detected. Use space instead"));
	line_splitted = ft_split_colorstr(line);
	if (line_splitted == NULL)
		return (false);
	if (ft_check_color_line(line_splitted, infoid) == false)
	{
		ft_free_2d_array_nullterminated((void **) line_splitted);
		return (ft_write_error("Incorrect line in .cub file"));
	}
	success_read_color = ft_extract_color(line_splitted[1], color);
	ft_free_2d_array_nullterminated((void **) line_splitted);
	return (success_read_color);
}
