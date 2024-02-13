/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:08:31 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/11/01 08:47:36 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_free_struct(t_data *data)
{
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->image_northwall != NULL)
		mlx_destroy_image(data->mlx, data->image_northwall);
	if (data->image_eastwall != NULL)
		mlx_destroy_image(data->mlx, data->image_eastwall);
	if (data->image_southwall != NULL)
		mlx_destroy_image(data->mlx, data->image_southwall);
	if (data->image_westwall != NULL)
		mlx_destroy_image(data->mlx, data->image_westwall);
	if (data->image_door != NULL)
		mlx_destroy_image(data->mlx, data->image_door);
	ft_free_2d_array_nullterminated((void **) data->map);
}

t_rgb	ft_create_rgb(int r_value, int g_value, int b_value)
{
	t_rgb	rgb;

	if (r_value < 0 || g_value < 0 || b_value < 0
		|| r_value > 255 || g_value > 255 || b_value > 255)
	{
		r_value = -1;
		g_value = -1;
		b_value = -1;
	}
	rgb.r = r_value;
	rgb.g = g_value;
	rgb.b = b_value;
	return (rgb);
}

void	ft_free_lstcontent(void *content)
{
	free(content);
}

bool	ft_write_error(char *error_msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(error_msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (false);
}
