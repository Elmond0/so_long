/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:46:21 by elmondo           #+#    #+#             */
/*   Updated: 2025/04/26 20:50:59 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	ft_memset(game, 0, sizeof(t_game));
	game->error = 3;
	if (!game)
		return (error_message(3, game), 1);
	if (argc == 2 && ft_check_extention(argv[1]) == 1)
	{
		game = map_init(argv[1], game);
		if (map_valid_allrequisites(game->map, argv[1], game))
		{
			game_init_master(game);
			game_play(game);
			mlx_loop(game->data_mlx->connect);
		}
		free_dp_char(game->map->map_skeleton);
		free(game->map);
		free(game);
	}
	else
		error_message(1, game);
	return (0);
}
