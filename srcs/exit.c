/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raisufaj <raisufaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:00:23 by raisufaj          #+#    #+#             */
/*   Updated: 2025/05/16 20:08:41 by raisufaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Manages window termination */
void	ft_close_game(t_data *data)
{
	ft_printf("You quit the game!\n");
	ft_printf("Jack ate %d chocolates!\n", data->count.score);
	ft_printf("There are still %d chocolates running free!\n", data->count.col);
	ft_remove_normal(data);
	exit(1);
}

/* Ends the game while printing player's final score and moves */
void	ft_game_success(t_data *data)
{
	ft_printf("Well Done!\n");
	ft_printf("Jack ate %d chocolates in %d moves!\n", data->count.score,
		data->count.moves);
	ft_remove_normal(data);
	exit(1);
}

/* Manages window termination by clicking X */
int	cross_close(t_data *data)
{
	ft_close_game(data);
	return (0);
}
