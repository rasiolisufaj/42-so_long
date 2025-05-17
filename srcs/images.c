/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 22:08:39 by raisufaj          #+#    #+#             */
/*   Updated: 2025/05/16 23:58:02 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Gets image from files */
void	ft_get_images(t_data *data)
{
	data->img.path_player = "textures/player.xpm";
	data->img.player = mlx_xpm_file_to_image(data->mlx, data->img.path_player,
			&data->img.width, &data->img.height);
	data->img.path_player_sick = "textures/player_sick.xpm";
	data->img.player_sick = mlx_xpm_file_to_image(data->mlx,
			data->img.path_player_sick, &data->img.width, &data->img.height);
	data->img.path_wall = "textures/wall.xpm";
	data->img.wall = mlx_xpm_file_to_image(data->mlx, data->img.path_wall,
			&data->img.width, &data->img.height);
	data->img.path_ground = "textures/grass.xpm";
	data->img.ground = mlx_xpm_file_to_image(data->mlx, data->img.path_ground,
			&data->img.width, &data->img.height);
	data->img.path_col = "textures/chocolate.xpm";
	data->img.col = mlx_xpm_file_to_image(data->mlx, data->img.path_col,
			&data->img.width, &data->img.height);
	data->img.path_exit_closed = "textures/exit_closed.xpm";
	data->img.exit_closed = mlx_xpm_file_to_image(data->mlx,
			data->img.path_exit_closed, &data->img.width, data->img.height);
	data->img.path_exit_open = "textures/exit_open.xpm";
	data->img.exit_open = mlx_xpm_file_to_image(data->mlx,
			data->img.path_exit_open, &data->img.width, data->img.height);
	ft_check_images(data);
}

/* Checks MLX images one by one and calls ft_remove
function to destroy and free appropriately */
void	ft_check_images(t_data *data)
{
	t_items items;

	items = 42;
	if (data->img.player == NULL)
	{
		ft_printf("ERROR\nImage_player does not exist!\n");
		ft_remove_images(data, img_player);
	}
}
