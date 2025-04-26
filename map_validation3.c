/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:42:33 by elmondo           #+#    #+#             */
/*   Updated: 2025/04/26 18:52:47 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	shape(t_map *map, t_game *game)
{
    if (map->qt_lines == map->qt_chars_lines)
		return (error_message4(12, game), 0);
	return (1);
}
void	error_message4(int flag, t_game *game)
{
	if (game->error == 3)
		write(2, "Error\n", 6);
	if (flag == 12)
	{
		write(2, "Maps not rectangular.\n", 22);
		game->error = 1;
	}
}
