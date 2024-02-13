/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hands.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpsyk <lpsyk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:48:29 by lpsyk             #+#    #+#             */
/*   Updated: 2022/10/31 15:30:22 by lpsyk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/draw.h"

int	ft_mouse_hook(int x, int y, t_data *data)
{
	static int	prev;
	int			current;

	if (data->mouse_turn == false)
		return (y);
	current = x;
	if (current < prev)
	{
		data->player_angle += TURN_SPEED;
	}
	else if (current > prev)
	{
		data->player_angle -= TURN_SPEED;
	}
	data->player_angle = ft_norm_angle(data->player_angle);
	prev = current;
	return (y);
}

static int	ft_destroy_hand_imgs(t_data *data, t_hand_imgs *hand_imgs)
{
	if (hand_imgs->left_hand.img != NULL)
		mlx_destroy_image(data->mlx, hand_imgs->left_hand.img);
	if (hand_imgs->right_hand.img != NULL)
		mlx_destroy_image(data->mlx, hand_imgs->right_hand.img);
	return (EXIT_FAILURE);
}

static bool	ft_is_movement(int keycode)
{
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
		return (true);
	return (false);
}

static void	ft_draw_hands(t_data *data, t_hand_imgs *hand_imgs, int left)
{
	mlx_put_image_to_window(data->mlx, data->win,
		hand_imgs->left_hand.img, 0, left + 30);
	mlx_put_image_to_window(data->mlx, data->win,
		hand_imgs->right_hand.img, 0, left * -1 + 30);
	ft_destroy_hand_imgs(data, hand_imgs);
}

int	ft_animate_hands(int keycode, t_data *data)
{
	t_hand_imgs	hand_imgs;
	static int	left;
	static bool	up;
	int			width;
	int			height;

	if (data->show_hands == false)
		return (EXIT_SUCCESS);
	hand_imgs.left_hand.img = mlx_xpm_file_to_image(data->mlx,
			"./texture/left_hand.xpm", &width, &height);
	hand_imgs.right_hand.img = mlx_xpm_file_to_image(data->mlx,
			"./texture/right_hand.xpm", &width, &height);
	if (hand_imgs.left_hand.img == NULL || hand_imgs.right_hand.img == NULL)
		return (ft_destroy_hand_imgs(data, &hand_imgs));
	if (left == -30)
		up = true;
	else if (left == 30)
		up = false;
	if (up == true && ft_is_movement(keycode) == true)
		left += 2;
	else if (ft_is_movement(keycode) == true)
		left -= 2;
	ft_draw_hands(data, &hand_imgs, left);
	return (EXIT_SUCCESS);
}
