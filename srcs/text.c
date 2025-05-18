/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:46:34 by raisufaj          #+#    #+#             */
/*   Updated: 2025/05/18 16:16:17 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Displays score, moves and fixes text on the window */
void	ft_put_score(t_data *data)
{
	char	*move_or_score;
	char	*final_text;

	move_or_score = ft_itoa(data->count.moves);
	final_text = ft_strjoin("MOVES = ", move_or_score);
	mlx_set_font(data->mlx, data->win, "10x20");
	mlx_string_put(data->mlx, data->win, 2, 40, 0x00BFFF, final_text);
	free(move_or_score);
	free(final_text);
	move_or_score = ft_itoa(data->count.score);
	final_text = ft_strjoin("CHOCOLATES = ", move_or_score);
	mlx_string_put(data->mlx, data->win, 82, 60, 0x5FFB17, final_text);
	mlx_string_put(data->mlx, data->win, 40, 20, 0xFFFFFF, "S O    L O N G");
	mlx_string_put(data->mlx, data->win, 22, data->map.map_x * 80 - 52,
		0xDAEE01, "DINO IS HUNGRY...");
	free(move_or_score);
	free(final_text);
	ft_check_col(data);
}

/* If no more collectibles are present on the map, rewrites a string
with the same color as the brick (wall) to erase the previous message
and shows a new message on the map */
void	ft_check_col(t_data *data)
{
	if (data->count.col == 0)
	{
		mlx_set_font(data->mlx, data->win, "10x20");
		mlx_string_put(data->mlx, data->win, 22, data->map.map_x * 80 - 52,
			0x800000, "DINO IS HUNGRY...");
		mlx_string_put(data->mlx, data->win, 22, data->map.map_x * 80 - 52,
			0xFE817, "DINO IS NOW SICK...");
		mlx_string_put(data->mlx, data->win, 52, data->map.map_x * 80 - 32,
			0xFFA500, "TAKE HIM TO");
		mlx_string_put(data->mlx, data->win, 82, data->map.map_x * 80 - 12,
			0xFFA500, "THE HOSPITAL!");
	}
}
