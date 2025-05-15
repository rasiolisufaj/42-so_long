/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:46:27 by raisufaj          #+#    #+#             */
/*   Updated: 2025/05/15 17:32:38 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Read map with GNL */
void	ft_read_maps(t_data *data)
{
	int		fd;
	char	*file;
	char	*line;
	char	*tmp;

	file = data->arguments;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("ERROR\nCan't read the map!\n");
		exit(1);
	}
	line = get_next_line(fd);
	tmp = NULL;
	while (line)
	{
	}
}
