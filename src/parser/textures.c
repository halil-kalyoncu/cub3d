/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:21:45 by lpsyk             #+#    #+#             */
/*   Updated: 2022/10/31 16:05:15 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static bool	ft_check_texture_line(char **line_splitted)
{
	if (line_splitted[0] == NULL || line_splitted[1] == NULL
		|| line_splitted[2] != NULL)
	{
		return (ft_write_error("Incorrect line in .cub file"));
	}
	if (ft_strlen(line_splitted[0]) != 2)
	{
		return (ft_write_error("Incorrect line in .cub file"));
	}
	return (true);
}

static bool	ft_check_texture_already_set(t_infodata *infodata, t_infoid infoid)
{
	void	*texture_ptr;

	if (infoid == INFOID_NORTH)
		texture_ptr = infodata->image_northwall;
	else if (infoid == INFOID_EAST)
		texture_ptr = infodata->image_eastwall;
	else if (infoid == INFOID_SOUTH)
		texture_ptr = infodata->image_southwall;
	else
		texture_ptr = infodata->image_westwall;
	return (texture_ptr == NULL);
}

static void	ft_save_texture_ptr(t_infodata *infodata, t_infoid infoid,
	void *texture_ptr)
{
	if (infoid == INFOID_NORTH)
		infodata->image_northwall = texture_ptr;
	else if (infoid == INFOID_EAST)
		infodata->image_eastwall = texture_ptr;
	else if (infoid == INFOID_SOUTH)
		infodata->image_southwall = texture_ptr;
	else
		infodata->image_westwall = texture_ptr;
}

static int	ft_load_texture(t_infodata *infodata, t_infoid infoid,
	char **splitted)
{
	void	*texture_ptr;
	int		width;
	int		height;

	texture_ptr = mlx_xpm_file_to_image(infodata->mlx, splitted[1], &width,
			&height);
	if (texture_ptr == NULL)
		return (ft_write_error("Failed to load texture. "
				"Hint: Only accepting dimensions 64 x 64."));
	if (width != 64 || height != 64)
		return (ft_write_error("Failed to load texture. "
				"Hint: Only accepting dimensions 64 x 64."));
	ft_save_texture_ptr(infodata, infoid, texture_ptr);
	return (true);
}

int	ft_set_texture(t_infodata *infodata, t_infoid infoid, char *line)
{
	bool	success_load_texture;
	char	**line_splitted;

	if (ft_strchr(line, '\t') != NULL)
		return (ft_write_error("Tab detected. Use space instead"));
	line_splitted = ft_split(line, ' ');
	if (line_splitted == NULL)
		return (ft_write_error("No space left on device"));
	if (ft_check_texture_line(line_splitted) == false)
	{
		ft_free_2d_array_nullterminated((void **) line_splitted);
		return (false);
	}
	if (ft_check_texture_already_set(infodata, infoid) == false)
	{
		ft_free_2d_array_nullterminated((void **) line_splitted);
		return (ft_write_error("Only one texture per direction allowed"));
	}
	success_load_texture = ft_load_texture(infodata, infoid, line_splitted);
	ft_free_2d_array_nullterminated((void **) line_splitted);
	return (success_load_texture);
}
