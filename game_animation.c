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
