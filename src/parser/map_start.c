/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:22:26 by lpsyk             #+#    #+#             */
/*   Updated: 2022/10/26 14:05:14 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

void	ft_determine_map_dimensions(t_data *data, t_list *map)
{
	int		map_width;
	int		line_size;

	map_width = 0;
	while (map != NULL)
	{
		data->map_dimension.y++;
		line_size = (int) ft_strlen((char *) map->content);
		if (line_size > map_width)
		{
			map_width = line_size;
		}
		map = map->next;
	}
	data->map_dimension.x = map_width;
}

bool	ft_check_mapline(const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr(" 012NSEW", line[i]) == NULL)
			return (false);
		i++;
	}
	return (true);
}

static char	*ft_create_whitespace(int size)
{
	char	*str;
	int		i;

	str = (char *) malloc((size + 1) * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_create_mapline(const char *lstline, int map_width)
{
	char	*mapline;
	char	*whitespace;

	whitespace = ft_create_whitespace(map_width - ft_strlen(lstline));
	if (whitespace == NULL)
		return (NULL);
	mapline = ft_strjoin(lstline, whitespace);
	free(whitespace);
	return (mapline);
}

char	**ft_init_map(t_list *lstmap, t_position map_dimension)
{
	char	**map;
	int		i;

	map = (char **) malloc((map_dimension.y + 1) * sizeof(char *));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (lstmap != NULL)
	{
		map[i] = ft_create_mapline((char *) lstmap->content, map_dimension.x);
		if (map[i] == NULL)
		{
			ft_free_2d_array((void **) map, i);
			return (NULL);
		}
		lstmap = lstmap->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}
