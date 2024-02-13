/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:02:10 by lpsyk             #+#    #+#             */
/*   Updated: 2022/11/01 08:59:00 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "cub3d.h"

/* Mac-Keycodes */
# define KEY_A 0
# define KEY_D 2
# define KEY_W 13
# define KEY_S 1
# define KEY_O 31
# define KEY_H 4
# define KEY_C 8
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define KEY_M 46

/* Raycasting utils */
# define PROJECTION_WIDTH 1024
# define PROJECTION_HEIGHT 512

# define TILE_SIZE 64.f
# define FOV 60.f
# define HFOV 30.f
# define DISTANCE_PROJECTION 277.f

# define MOVE_SPEED 1
# define TURN_SPEED 1.f

# define MAP_WIDTH 5
# define MAP_HEIGHT 5
# define MAP_TILESIZE 16
# define MAP_COLORFLOOR 0x40FFFFFF
# define MAP_COLORWALL 0x40000000
# define MAP_COLOROUTSIDE 0x40FFFFFF
# define MAP_COLORTILEEDGE 0x40808080
# define MAP_COLORDOORCLOSED 0x40FF0000
# define MAP_COLORDOOROPEN 0x4000FF00
# define MAP_COLORPLAYER 0x40000000
# define MAP_COLORPLAYEREDGE 0x40FF0000
# define MAP_OFFSETX 10
# define MAP_OFFSETY 10

# define CORNER_PADDING 0.2f

// exit
# include <stdlib.h>
# include <math.h>

typedef struct s_intersection
{
	t_coordinate	hit_coord;
	int				texture_slice;
	float			distance;
	bool			hit_door;
}	t_intersection;

typedef struct s_ray
{
	int		index;
	float	angle;
	float	offset;
	float	fisheye_angle;
	void	*image_northwall;
	void	*image_eastwall;
	void	*image_southwall;
	void	*image_westwall;
	void	*image_door;
}	t_ray;

typedef struct s_slice_line
{
	int	height;
	int	offset;
}	t_slice_line;

typedef struct s_slice_texture
{
	float	step;
	int		offset;
}	t_slice_texture;

typedef enum e_corner_id
{
	CORNER_UPLEFT = 0,
	CORNER_UPRIGHT = 1,
	CORNER_DOWNRIGHT = 2,
	CORNER_DOWNLEFT = 3
}	t_corner_id;

typedef struct s_hand_imgs
{
	t_image	right_hand;
	t_image	left_hand;
}	t_hand_imgs;

// mlx_utils.c
void			ft_mlx_pixel_put(t_image *img, int x, int y, int color);
unsigned int	ft_mlx_pixel_get(t_image img, int x, int y);

// math.c
float			ft_tangens(float degree);
float			ft_cosinus(float degree);
float			ft_sinus(float degree);
t_position		ft_calc_grid_position(t_coordinate coord);
float			ft_calc_slope(t_coordinate origin, t_coordinate point);

// raycasting.c
void			ft_draw_projection(t_data *data);

// draw.c
void			ft_draw(t_data *data);

// move.c
void			ft_move(int keycode, t_data *data);

// angles.c
float			ft_norm_angle(float angle);
bool			ft_check_angle_facing_up(float angle);
bool			ft_check_angle_facing_right(float angle);

// raycasting_utils.c
float			ft_calc_distance(t_coordinate origin, t_coordinate hit);
int				ft_calc_color_value(t_rgb rgb);
t_image			ft_create_projection_image(void *mlx, int width,
					int height, t_data *data);
void			ft_draw_slice(int column, t_intersection inter, t_image *image,
					t_image *texture_image);

// draw_utils.c
t_position		ft_jump_to_first_pos(t_coordinate player_coord);
void			ft_turn(int keycode, t_data *data);

// map.c
void			ft_fill_map_tile(t_position pos, t_position map_pos,
					t_data *data, t_image *img);
void			ft_fill_map(t_data *data, t_image *img);
void			ft_draw_map(t_data *data);

// map_utils.c
t_image			ft_create_transparent_image(void *mlx, int width, int height);
bool			ft_check_pos_outside_map(t_position pos,
					t_position map_dimension);
int				ft_look_up_tile_color(t_position pos, t_data *data);

// intersection.c
t_intersection	ft_compare_intersections(t_intersection horizontal_int,
					t_intersection vertical_int, t_ray *ray,
					t_image *texture_image);

// intersection_horizontal.c
t_intersection	ft_calc_horizontal_int(float ray_angle, t_data *data);

// intersection_vertical.c
t_intersection	ft_calc_vertical_int(float ray_angle, t_data *data);

// intersection_utils1.c
float			ft_look_up_bigger_side(t_coordinate max_coord);
int				ft_look_up_bigger_grid(t_position map_dimensions);
bool			ft_check_hit_wall(t_position pos, char **map);
bool			ft_check_hit_door(t_position pos, char **map);

// intersection_utils2.c
bool			ft_check_horizontal_corner(t_coordinate coord, t_position pos,
					float ray_angle, char **map);
bool			ft_check_vertical_corner(t_coordinate coord, t_position pos,
					float ray_angle, char **map);

/* BONUS */
// hands.c
int				ft_mouse_hook(int x, int y, t_data *data);
int				ft_animate_hands(int keycode, t_data *data);

// doors.c
t_position		ft_open_door(t_data *data);
void			ft_close_door(t_position door_pos, t_data *data);

#endif