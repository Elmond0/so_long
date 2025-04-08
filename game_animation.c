#include "so_long.h"

int	coin_animation(t_game *game)
{
	if (game->coin->coin_loop < 7000)
	{
		game->coin->coin_loop++;
		return (0);
	}
	game->coin->coin_loop = 0;
	if (game->coin->coin_pos >= 6 || game->coin->coin_pos <= 0)
		game->coin->coin_pos = 0;
	draw_mapcoins(game);
	game->coin->coin_pos++;
	return (0);
}

int	exit_animation(t_game *game)
{
	if (game->exit->exit_loop < 7000)
	{
		game->exit->exit_loop++;
		return (0);
	}
	game->exit->exit_loop = 0;
	if (game->exit->exit_pos > 6)
		game->exit->exit_pos = 0;
	draw_exit(game);
	game->exit->exit_pos++;
	return (0);
}
