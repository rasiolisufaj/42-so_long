/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:15:53 by raisufaj          #+#    #+#             */
/*   Updated: 2025/05/21 11:39:54 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Checks if map contents (P, C, E) are valid */
bool	ft_check_map_contents(t_data *data)
{
	while (data->map.map[data->coords.x] != NULL)
	{
		data->coords.y = 0;
		while (data->map.map[data->coords.x][data->coords.y] != '\0')
		{
			if (data->map.map[data->coords.x][data->coords.y] == 'P')
			{
				data->coords.x_player = data->coords.x;
				data->coords.y_player = data->coords.y;
				data->count.player++;
			}
			else if (data->map.map[data->coords.x][data->coords.y] == 'E')
				data->count.exit++;
			else if (data->map.map[data->coords.x][data->coords.y] == 'C')
				data->count.col++;
			else if (data->map.map[data->coords.x][data->coords.y] != '0'
				&& data->map.map[data->coords.x][data->coords.y] != '1')
				return (false);
			data->coords.y++;
		}
		data->coords.x++;
	}
	if (data->count.player != 1 || data->count.exit != 1 || data->count.col < 1)
		return (false);
	return (true);
}

/* Checks if walls are enclosing the map correctly by
calling ft_check_lines and ft_check_columns */
void	ft_check_map_format(t_data *data)
{
	data->coords.x = 0;
	while (data->map.map[data->coords.x] != NULL)
		data->coords.x++;
	data->coords.y = 0;
	while (data->map.map[0][data->coords.y] != '\0')
		data->coords.y++;
	ft_check_rectangular(data);
	ft_check_lines(data, 0);
	ft_check_lines(data, data->coords.x - 1);
	ft_check_columns(data, 0);
	ft_check_columns(data, data->coords.y - 1);
}

/* Checks if the map is rectangular by comparing the first
row size to the whole map */
void	ft_check_rectangular(t_data *data)
{
	int	x;
	int	y;
	int	check_y;

	x = 0;
	y = 0;
	while (data->map.map[0][y] != '\0')
		y++;
	while (data->map.map[x] != NULL)
	{
		check_y = 0;
		while (data->map.map[x][check_y] != '\0')
			check_y++;
		if (check_y != y)
		{
			ft_printf("ERROR\nThe map is not rectangular!\n");
			ft_free_map(data);
			exit(1);
		}
		x++;
	}
	data->map.map_x = x;
	data->map.map_y = y;
}

/* Checks if walls (1) are present on column number n */
void	ft_check_columns(t_data *data, int n)
{
	data->coords.x = 0;
	while (data->map.map[data->coords.x] != NULL)
	{
		if (data->map.map[data->coords.x][n] != '1')
		{
			ft_printf("ERROR\n");
			ft_printf("Open map on line n%d and column n%d!\n", data->coords.x,
				n);
			ft_printf("The chocolates will escape...\n");
			ft_free_map(data);
			exit(1);
		}
		data->coords.x++;
	}
}

/* Checks if walls (1) are present on line number n */
void	ft_check_lines(t_data *data, int n)
{
	data->coords.y = 0;
	while (data->map.map[n][data->coords.y] != '\0')
	{
		if (data->map.map[n][data->coords.y] != '1')
		{
			ft_printf("ERROR\n");
			ft_printf("Open map on line n%d and column n%d!\n", data->coords.y,
				n);
			ft_printf("The chocolates will escape...\n");
			ft_free_map(data);
			exit(1);
		}
		data->coords.y++;
	}
}
