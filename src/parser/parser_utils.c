/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:42:12 by lpsyk             #+#    #+#             */
/*   Updated: 2022/10/26 16:23:47 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

int	ft_set_color(t_infodata *infodata, t_infoid infoid, char *line)
{
	t_rgb	current_color;
	t_rgb	color;

	if (infoid == INFOID_FLOOR)
		current_color = infodata->color_floor;
	else
		current_color = infodata->color_ceiling;
	if (current_color.r != -1)
		return (ft_write_error("Only one color for floor and ceiling allowed"));
	if (ft_read_color(line, infoid, &color) == false)
		return (false);
	if (infoid == INFOID_FLOOR)
		infodata->color_floor = color;
	else
		infodata->color_ceiling = color;
	return (true);
}

static void	ft_check_ready(t_infodata *infodata)
{
	bool	check_set_every_information;

	check_set_every_information = (infodata->image_northwall != NULL
			&& infodata->image_eastwall != NULL
			&& infodata->image_southwall != NULL
			&& infodata->image_westwall != NULL
			&& infodata->color_floor.r != -1
			&& infodata->color_ceiling.r != -1);
	if (check_set_every_information == false)
	{
		ft_write_error("Missing information");
		infodata->ready = READY_ERROR;
		return ;
	}
	infodata->ready = READY_CONTINUE;
}

int	ft_add_mapline(t_infodata *infodata, t_infoid infoid, char *line)
{
	t_list	*lstnode;
	char	*mapline;

	if (infodata->ready == READY_NOTCHECKED)
		ft_check_ready(infodata);
	if (infodata->ready == READY_ERROR)
		return (false);
	mapline = ft_strdup(line);
	if (mapline == NULL)
		return (ft_write_error("No space left on device"));
	lstnode = ft_lstnew(mapline);
	if (lstnode == NULL)
	{
		free(mapline);
		return (ft_write_error("No space left on device"));
	}
	ft_lstadd_back(&infodata->map, lstnode);
	return (true);
	(void) infoid;
}

int	ft_found_incorrect_line(t_infodata *infodata, t_infoid infoid,
	char *line)
{
	return (ft_write_error("Incorrect line in .cub file"));
	(void) infodata;
	(void) infoid;
	ft_putstr_fd(line, STDERR_FILENO);
}
