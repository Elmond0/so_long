#include "so_long.h"

void	free_exit_imgptr(t_game *game)
{
	t_mlx_data	*connect;

	connect = game->data_mlx->connect;
	mlx_destroy_image(connect, game->exit->e_imgs[0]);
}
