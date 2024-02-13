/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 08:47:01 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/11/01 11:31:04 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

# define PATH_DOOR "texture/door.xpm"

typedef enum e_infoid
{
	INFOID_EMPTY = 0,
	INFOID_NORTH = 1,
	INFOID_EAST = 2,
	INFOID_SOUTH = 3,
	INFOID_WEST = 4,
	INFOID_FLOOR = 5,
	INFOID_CEILING = 6,
	INFOID_MAP = 7,
	INFOID_FAIL = 8
}	t_infoid;

typedef enum e_ready
{
	READY_NOTCHECKED = 0,
	READY_CONTINUE = 1,
	READY_ERROR = 2
}	t_ready;

typedef struct s_infodata
{
	t_list	*map;
	void	*image_northwall;
	void	*image_eastwall;
	void	*image_southwall;
	void	*image_westwall;
	t_rgb	color_floor;
	t_rgb	color_ceiling;
	t_ready	ready;
	void	*mlx;
}	t_infodata;

bool		ft_run_parser(t_data *data, const char *file_path);

// map_start.c
void		ft_determine_map_dimensions(t_data *data, t_list *map);
bool		ft_check_mapline(const char *line);
char		**ft_init_map(t_list *lstmap, t_position map_dimension);

// map_position.c
bool		ft_search_starting_pos(t_data *data);

// map_utils1.c
char		**ft_create_map_copy(char **map, int map_height);
bool		ft_push_front(t_list **stack, int x, int y);
t_position	ft_pop_front(t_list **stack);
bool		ft_check_passed_map_edge(t_position pos, t_position map_dimension);
bool		ft_push_neighbors(t_list **stack, t_position pos);

// map_utils2.c
bool		ft_check_closed(char **map, t_position map_dimension,
				t_position player_pos);

// init.c
bool		ft_init_data(t_data *data);
void		ft_init_infodata(t_infodata *infodata, void *mlxptr);
void		ft_free_infodata(t_infodata *infodata);
t_infoid	ft_identify_line(char *line, t_infodata *infodata);

// textures.c
int			ft_set_texture(t_infodata *infodata, t_infoid infoid, char *line);

// color.c
bool		ft_read_color(char *line, t_infoid infoid, t_rgb *color);

// color_utils.c
char		**ft_split_colorstr(const char *str);
bool		ft_check_rgb_str(char *rgb_str);

// parser_utils.c
int			ft_set_color(t_infodata *infodata, t_infoid infoid, char *line);
int			ft_add_mapline(t_infodata *infodata, t_infoid infoid, char *line);
int			ft_found_incorrect_line(t_infodata *infodata, t_infoid infoid,
				char *line);

#endif