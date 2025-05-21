/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:35:48 by raisufaj          #+#    #+#             */
/*   Updated: 2025/05/21 11:56:02 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Checks if maps are in the correct format .ber by calling ft_is_map_ber.
Then proceeds to open the map and calls all checking functions*/

void	ft_check_map_name(t_data *data)
{
	if (ft_is_map_ber(data->arguments, ".ber") == false)
	{
		ft_printf("ERROR\nInvalid map extension!\n");
		exit(1);
	}
	ft_read_maps(data);
	ft_check_map_format(data);
	ft_map_status(data);
	ft_check_flood_fill(data);
}

/* Checks if the last 4 chars of the map file name is ".ber" */
bool	ft_is_map_ber(char *str, char *to_compare)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(str) - 4;
	j = 0;
	while (str[i] || to_compare[j])
	{
		if (str[i] != to_compare[j])
			return (false);
		i++;
		j++;
	}
	return (true);
}

/* Checks if map contents are valid */
void	ft_map_status(t_data *data)
{
	data->coords.x = 0;
	data->count.player = 0;
	data->count.exit = 0;
	data->count.col = 0;
	if (ft_check_map_contents(data) == false)
	{
		ft_printf("ERROR\nInvalid map contents!\n");
		ft_free_map(data);
		exit(1);
	}
}

/* Checks if path is valid */
void	ft_check_flood_fill(t_data *data)
{
	ft_init_map_dup(data);
	if (ft_flood_fill(data, data->coords.x_player,
			data->coords.y_player) == false)
	{
		ft_printf("ERROR\nInvalid pathing!\n");
		ft_free_map_both(data);
		exit(1);
	}
}

void	ft_check_newline_integrity(char *map_str)
{
	int i;

	i = 0;
	while (map_str[i] && map_str[i + 1])
	{
		if (map_str[i] == '\n' && map_str[i + 1] == '\n')
		{
			ft_printf("ERROR\nMap contains an empty line!\n");
			free(map_str);
			exit(1);
		}
		i++;
	}
}