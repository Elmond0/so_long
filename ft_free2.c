#include "so_long.h"

void	free_exit_imgptr(t_game *game)
{
	t_mlx_data	*connect;
	int			i;

	i = 0;
	connect = game->data_mlx->connect;
	while (i <= 9)
		mlx_destroy_image(connect, game->exit->e_imgs[i++]);
}
