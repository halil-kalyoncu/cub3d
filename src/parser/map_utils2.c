/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:24:58 by lpsyk             #+#    #+#             */
/*   Updated: 2022/11/01 10:53:38 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static bool	ft_error_floodfill(char *error_msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("Invalid map, ", STDERR_FILENO);
	ft_putstr_fd(error_msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (false);
}

static bool	ft_check_push_neighbors(t_list **stack, t_position pos)
{
	if (ft_push_neighbors(stack, pos) == false)
	{
		ft_write_error("No space left on device");
		return (false);
	}
	return (true);
}

static bool	ft_flood_fill(char **map, t_position map_dimension,
	t_position player_pos)
{
	bool		closed_by_wall;
	t_list		*stack;
	t_position	pos;

	closed_by_wall = true;
	stack = NULL;
	if (ft_push_front(&stack, player_pos.x, player_pos.y) == false)
		ft_write_error("No space left on device");
	while (ft_lstsize(stack) > 0 && closed_by_wall == true)
	{
		pos = ft_pop_front(&stack);
		if (ft_check_passed_map_edge(pos, map_dimension) == true)
			closed_by_wall = ft_error_floodfill("not surrounded by walls");
		else
		{
			if (map[pos.y][pos.x] == ' ')
				closed_by_wall = ft_error_floodfill("No spaces allowed inside");
			else if (map[pos.y][pos.x] != '1')
				closed_by_wall = ft_check_push_neighbors(&stack, pos);
			map[pos.y][pos.x] = '1';
		}
	}
	ft_lstclear(&stack, ft_free_lstcontent);
	return (closed_by_wall);
}

bool	ft_check_closed(char **map, t_position map_dimension,
	t_position player_pos)
{
	int		closed_by_wall;
	char	**copy_map;

	copy_map = ft_create_map_copy(map, map_dimension.y);
	if (copy_map == NULL)
		return (ft_write_error("No space left on device"));
	closed_by_wall = ft_flood_fill(copy_map, map_dimension, player_pos);
	ft_free_2d_array_nullterminated((void **) copy_map);
	return (closed_by_wall);
}
