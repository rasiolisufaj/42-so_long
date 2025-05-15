/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:01:17 by raisufaj          #+#    #+#             */
/*   Updated: 2025/05/15 15:27:09 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments!\n");
		exit(1);
	}
	data.arguments = argv[1];
	ft_check_map_name(&data);
	data.count.moves = 0;
	data.count.score = 0;
	data.mlx = mlx_init();
	ft_check_mlx(&data);
	data.win = mlx_new_window(data.mlx, data.map.map_y * 80, data.map.map_x
			* 80, "so_long");
	ft_check_mlx_win(&data);
	ft_get_images(&data);
	ft_put_images_to_map(&data);
	ft_put_score(&data);
	mlx_hook(data.win, 2, KeyPressMask, ft_put_images_to_map, &data);
	mlx_hook(data.win, 2, KeyPressMask, ft_key_press, &data);
	mlx_hook(data.win, 17, StructureNotifyMask, cross_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
