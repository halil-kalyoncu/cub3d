/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkalyonc <hkalyonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 08:47:57 by hkalyonc          #+#    #+#             */
/*   Updated: 2022/11/01 11:34:53 by hkalyonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../include/parser.h"
#include "../include/draw.h"

static bool	ft_check_file_extension(const char *file_path)
{
	size_t	size_filename;
	int		index_dot;

	size_filename = ft_strlen(file_path);
	if (size_filename < 5)
	{
		return (false);
	}
	index_dot = size_filename - 4;
	return (ft_strncmp(&file_path[index_dot], ".cub", 4) == 0);
}

static void	ft_print_instructions(void)
{
	ft_putendl_fd("KEY(S)\t\t\tFUNCTION\n", STDOUT_FILENO);
	ft_putendl_fd("w-a-s-d\t\t\tmove", STDOUT_FILENO);
	ft_putendl_fd("left/right key\t\tturn around", STDOUT_FILENO);
	ft_putendl_fd("m\t\t\tshow/hide minimap", STDOUT_FILENO);
	ft_putendl_fd("o\t\t\topen door (when standing in front of it)",
		STDOUT_FILENO);
	ft_putendl_fd("h\t\t\tshow/hide hands", STDOUT_FILENO);
	ft_putendl_fd("c\t\t\tenable/disable mouse turn", STDOUT_FILENO);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		return (ft_write_error("No file found as input"));
	if (argc > 2)
		return (ft_write_error("Too many parameters"));
	if (ft_check_file_extension(argv[1]) == false)
		return (ft_write_error("Wrong file extension"));
	data.mlx = mlx_init();
	if (ft_run_parser(&data, argv[1]) == false)
	{
		ft_free_struct(&data);
		return (EXIT_FAILURE);
	}
	ft_print_instructions();
	ft_draw(&data);
	return (EXIT_SUCCESS);
}
