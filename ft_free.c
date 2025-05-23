/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:47:53 by elmondo           #+#    #+#             */
/*   Updated: 2025/04/13 16:48:49 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_dp_char(char **dp_char)
{
	int	i;

	i = 0;
	if (!dp_char)
		return ;
	while (dp_char[i])
	{
		free(dp_char[i]);
		i ++;
	}
	free(dp_char);
}

void	free_game_struct(t_game *game)
{
	free_dp_char(game->map->map_skeleton);
	free(game->map);
	free(game->data_mlx->connect);
	free(game->data_mlx->window);
	free(game->data_mlx);
	free(game);
}

void	free_map_imgptr(t_game *game)
{
	mlx_destroy_image(game->data_mlx->connect, game->map->img_floor);
	mlx_destroy_image(game->data_mlx->connect, game->map->img_murr);
	mlx_destroy_image(game->data_mlx->connect, game->map->img_wallbc);
	mlx_destroy_image(game->data_mlx->connect, game->map->img_wallbl);
	mlx_destroy_image(game->data_mlx->connect, game->map->img_wallbr);
	mlx_destroy_image(game->data_mlx->connect, game->map->img_wallc);
	mlx_destroy_image(game->data_mlx->connect, game->map->img_walll);
	mlx_destroy_image(game->data_mlx->connect, game->map->img_wallml);
	mlx_destroy_image(game->data_mlx->connect, game->map->img_wallmr);
	mlx_destroy_image(game->data_mlx->connect, game->map->img_wallr);
}

void	free_player_imgptr(t_game *game)
{
	mlx_destroy_image(game->data_mlx->connect, game->player->img_sback);
	mlx_destroy_image(game->data_mlx->connect, game->player->img_sfront);
	mlx_destroy_image(game->data_mlx->connect, game->player->img_sleft);
	mlx_destroy_image(game->data_mlx->connect, game->player->img_sright);
	mlx_destroy_image(game->data_mlx->connect, game->player->img_wback);
	mlx_destroy_image(game->data_mlx->connect, game->player->img_wback2);
	mlx_destroy_image(game->data_mlx->connect, game->player->img_wfront);
	mlx_destroy_image(game->data_mlx->connect, game->player->img_wfront2);
	mlx_destroy_image(game->data_mlx->connect, game->player->img_wright);
	mlx_destroy_image(game->data_mlx->connect, game->player->img_wright2);
	mlx_destroy_image(game->data_mlx->connect, game->player->img_wleft);
	mlx_destroy_image(game->data_mlx->connect, game->player->img_wleft2);
}

void	free_coin_imgptr(t_game *game)
{
	t_mlx_data	*connect;

	connect = game->data_mlx->connect;
	mlx_destroy_image(connect, game->coin->c_imgs[0]);
}
