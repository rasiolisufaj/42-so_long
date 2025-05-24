/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:46:27 by raisufaj          #+#    #+#             */
/*   Updated: 2025/05/24 17:50:29 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Read map with GNL */
static int	ft_open_map(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("ERROR\nCan't read the map!\n");
		exit(1);
	}
	if (read(fd, 0, 0) < 0)
	{
		close(fd);
		ft_printf("ERROR\n'%s' is a directory!\n", file);
		exit(1);
	}
	return (fd);
}

void	ft_read_maps(t_data *data)
{
	int		fd;
	char	*file;
	char	*line;
	char	*tmp;
	char	*joined;

	file = data->arguments;
	fd = ft_open_map(file);
	tmp = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		joined = ft_strjoin(tmp, line);
		free(tmp);
		tmp = joined;
		free(line);
		line = get_next_line(fd);
	}
	ft_check_empty_map(tmp, fd);
	close(fd);
	ft_check_newline_integrity(tmp);
	data->map.map = ft_split(tmp, '\n');
	free(tmp);
}

/* Places exit images */
void	ft_put_images_exit(t_data *data, int x, int y)
{
	ft_put_image(data, data->img.exit_closed, x, y);
	data->coords.x_exit = x;
	data->coords.y_exit = y;
}

/* Places player image */
void	ft_put_images_player(t_data *data, int x, int y)
{
	data->coords.x = x * data->img.height;
	data->coords.y = y * data->img.width;
	ft_put_image(data, data->img.player, x, y);
}

/* Places images according to map composition */
int	ft_put_images_to_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map.map[x])
	{
		y = 0;
		while (data->map.map[x][y] != '\0')
		{
			if (data->map.map[x][y] == '1')
				ft_put_image(data, data->img.wall, x, y);
			if (data->map.map[x][y] == '0')
				ft_put_image(data, data->img.ground, x, y);
			if (data->map.map[x][y] == 'C')
				ft_put_image(data, data->img.col, x, y);
			if (data->map.map[x][y] == 'P')
				ft_put_images_player(data, x, y);
			if (data->map.map[x][y] == 'E')
				ft_put_images_exit(data, x, y);
			y++;
		}
		x++;
		ft_open_exit(data);
	}
	return (0);
}
