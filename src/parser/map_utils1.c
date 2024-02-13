/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:24:52 by lpsyk             #+#    #+#             */
/*   Updated: 2022/10/31 10:17:07 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

char	**ft_create_map_copy(char **map, int map_height)
{
	char	**copy;
	int		i;

	copy = (char **) malloc((map_height + 1) * sizeof(char *));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < map_height)
	{
		copy[i] = ft_strdup(map[i]);
		if (copy[i] == NULL)
		{
			ft_free_2d_array((void **) copy, i);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

bool	ft_push_front(t_list **stack, int x, int y)
{
	t_position	*ptr;
	t_list		*stacknode;

	ptr = (t_position *) malloc(sizeof(t_position));
	if (ptr == NULL)
	{
		ft_lstclear(stack, ft_free_lstcontent);
		return (false);
	}
	ptr->x = x;
	ptr->y = y;
	stacknode = ft_lstnew((void *) ptr);
	if (stacknode == NULL)
	{
		free(ptr);
		ft_lstclear(stack, ft_free_lstcontent);
		return (false);
	}
	ft_lstadd_front(stack, stacknode);
	return (true);
}

t_position	ft_pop_front(t_list **stack)
{
	t_position	pos;
	t_list		*front_ptr;
	t_position	*front_pos;

	pos.x = -1;
	pos.y = -1;
	if (*stack == NULL)
	{
		return (pos);
	}
	front_ptr = *stack;
	front_pos = (t_position *) front_ptr->content;
	pos = *front_pos;
	*stack = (*stack)->next;
	front_ptr->next = NULL;
	ft_lstclear(&front_ptr, ft_free_lstcontent);
	return (pos);
}

bool	ft_check_passed_map_edge(t_position pos, t_position map_dimension)
{
	return (pos.y < 0 || pos.y >= map_dimension.y || pos.x < 0
		|| pos.x >= map_dimension.x);
}

bool	ft_push_neighbors(t_list **stack, t_position pos)
{
	if (ft_push_front(stack, pos.x, pos.y + 1) == false)
		return (false);
	if (ft_push_front(stack, pos.x, pos.y - 1) == false)
		return (false);
	if (ft_push_front(stack, pos.x + 1, pos.y) == false)
		return (false);
	if (ft_push_front(stack, pos.x - 1, pos.y) == false)
		return (false);
	if (ft_push_front(stack, pos.x + 1, pos.y + 1) == false)
		return (false);
	if (ft_push_front(stack, pos.x - 1, pos.y + 1) == false)
		return (false);
	if (ft_push_front(stack, pos.x + 1, pos.y - 1) == false)
		return (false);
	return (ft_push_front(stack, pos.x - 1, pos.y - 1));
}
