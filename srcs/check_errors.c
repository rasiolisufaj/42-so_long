/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:02:37 by raisufaj          #+#    #+#             */
/*   Updated: 2025/05/16 19:12:56 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Checks MLX initiation */
void	ft_check_mlx(t_data *data)
{
	if (!data->mlx)
	{
		ft_printf("ERROR\nMLX is not initiated!\n");
		ft_free_map_both(data);
		exit(1);
	}
}

/* Checks MLX windows conditions */
void	ft_check_mlx_win(t_data *data)
{
	if (!data->win)
	{
		ft_printf("ERROR\nThe window is not initiated!\n");
		ft_free_map_both(data);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
}
