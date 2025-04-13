/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_animation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:49:27 by elmondo           #+#    #+#             */
/*   Updated: 2025/04/13 16:49:27 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	coin_animation(t_game *game)
{
	draw_mapcoins(game);
	return (0);
}

int	exit_animation(t_game *game)
{
	draw_exit(game);
	return (0);
}
