/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:35:48 by raisufaj          #+#    #+#             */
/*   Updated: 2025/05/15 16:59:19 by raisufaj         ###   ########.fr       */
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
}

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
