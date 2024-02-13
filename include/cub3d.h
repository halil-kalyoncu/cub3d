/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:51:05 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/11/01 11:30:50 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/include/libft.h"
# include "../gnl/include/get_next_line.h"
# include "../minilibx/mlx.h"
// open
# include <fcntl.h>

// bool
# include <stdbool.h>

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_coordinate
{
	float	x;
	float	y;
}	t_coordinate;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_data
{
	char			**map;
	t_position		map_dimension;
	t_position		player_pos;
	t_coordinate	player_coord;
	float			player_angle;
	void			*mlx;
	void			*win;
	void			*image_northwall;
	void			*image_eastwall;
	void			*image_southwall;
	void			*image_westwall;
	void			*image_door;
	t_rgb			color_floor;
	t_rgb			color_ceiling;
	bool			show_map;
	t_coordinate	max_coord;
	bool			door_open;
	t_position		door_pos;
	t_image			door;
	bool			show_hands;
	bool			mouse_turn;
}	t_data;

void			ft_free_struct(t_data *data);
t_rgb			ft_create_rgb(int r_value, int g_value, int b_value);
void			ft_free_lstcontent(void *content);
bool			ft_write_error(char *error_msg);
t_position		ft_create_position(int x_value, int y_value);
t_coordinate	ft_create_coord(float x_value, float y_value);

#endif