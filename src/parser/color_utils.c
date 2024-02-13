/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:32:39 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/11/01 10:06:42 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parser.h"

static char	**ft_create_split(const char *str, int index_space)
{
	char	**split;

	split = (char **) malloc(3 * sizeof(char *));
	if (split == NULL)
	{
		ft_write_error("No space left on device");
		return (NULL);
	}
	split[0] = ft_substr(str, 0, index_space);
	split[1] = ft_substr(str, index_space + 1,
			ft_strlen(str) - index_space - 1);
	split[2] = NULL;
	if (split[0] == NULL || split[1] == NULL)
	{
		free(split[0]);
		free(split[1]);
		return (NULL);
	}
	return (split);
}

char	**ft_split_colorstr(const char *str)
{
	int		index_space;

	index_space = 0;
	while (str[index_space] != '\0' && str[index_space] != ' ')
		index_space++;
	if (str[index_space] == '\0')
	{
		ft_write_error("Incorrect line in .cub file");
		return (NULL);
	}
	return (ft_create_split(str, index_space));
}

static bool	ft_check_allowed_char(char c)
{
	return (ft_isdigit(c) == 1 || c == ' ');
}

static int	ft_jump_to_first_comma(char *rgb_str)
{
	int	i;

	i = 0;
	while (rgb_str[i] != '\0' && rgb_str[i] != ',')
	{
		if (ft_check_allowed_char(rgb_str[i]) == false)
			return (0);
		i++;
	}
	return (i);
}

bool	ft_check_rgb_str(char *rgb_str)
{
	int	i;
	int	index_start;

	i = ft_jump_to_first_comma(rgb_str);
	if (rgb_str[i] == '\0' || i == 0)
		return (false);
	index_start = i;
	i++;
	while (rgb_str[i] != '\0' && rgb_str[i] != ',')
	{
		if (ft_check_allowed_char(rgb_str[i]) == false)
			return (false);
		i++;
	}
	if (rgb_str[i] == '\0' || i == index_start)
		return (false);
	i++;
	index_start = i;
	while (rgb_str[i] != '\0' && ft_check_allowed_char(rgb_str[i]) == true)
		i++;
	return (rgb_str[i] == '\0' && i != index_start);
}
