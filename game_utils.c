/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:48:37 by elmondo           #+#    #+#             */
/*   Updated: 2025/04/13 16:48:37 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_close(t_game *game)
{
	free_dp_char(game->map->map_skeleton);
	free_map_imgptr(game);
	free_player_imgptr(game);
	free_coin_imgptr(game);
	free_exit_imgptr(game);
	mlx_destroy_window(game->data_mlx->connect, game->data_mlx->window);
	mlx_destroy_display(game->data_mlx->connect);
	free(game->map);
	free(game->player);
	free(game->coin);
	free(game->exit);
	free(game->data_mlx->connect);
	free(game->data_mlx);
	free(game);
	exit(0);
	return (0);
}

//check for image null values on the player and coin structures
//function just for debug, because if there is something NULL
//It will lead to seg fault
void	check_nullvalues_pc(t_game *game, char pointers)
{
	t_player	*gp;

	gp = game->player;
	if (pointers == 'p')
	{
		if (gp->img_sback == NULL || gp->img_sfront == NULL
			|| gp->img_sleft == NULL || gp->img_sright == NULL
			|| gp->img_wback == NULL || gp->img_wback2 == NULL
			|| gp->img_wfront == NULL || gp->img_wfront2 == NULL
			|| gp->img_wleft == NULL || gp->img_wleft2 == NULL
			|| gp->img_wright == NULL || gp->img_wright2 == NULL)
			ft_printf("ERROR AT GAME_GET_PLAYERIMG\n");
	}
	if (pointers == 'c')
	{
		if (game->coin->c_imgs[0] == NULL)
			ft_printf("ERROR AT GAME_GET_COINIMG\n");
	}
}

//check for image null values on the map structure
//function just for debug, because if there is something NULL
//It will lead to seg fault
void	check_nullvalues_me(t_game *game, char pointers)
{
	t_map	*map;
	t_exit	*ex;

	map = game->map;
	ex = game->exit;
	if (pointers == 'm')
	{
		if (map->img_floor == NULL || map->img_murr == NULL
			|| map->img_wallbl == NULL || map->img_wallbr == NULL
			|| map->img_wallc == NULL || map->img_walll == NULL
			|| map->img_wallml == NULL || map->img_wallmr == NULL
			|| map->img_wallr == NULL || game->map->img_wallbc == NULL)
			ft_printf("ERROR AT GAME_GET_MAPIMG\n");
	}
	if (pointers == 'e')
	{
		if (!ex->e_imgs[0])
			ft_printf("ERROR AT GAME_GET_EXITIMG\n");
	}
}

//Function that print the map skeleton on the terminal.
//return 1. 
int	map_print(t_map *map, char **map_copy)
{
	int		i;
	int		j;
	char	**lines;

	i = -1;
	lines = map_copy;
	while (lines[++i] != NULL)
	{
		j = 0;
		while (lines[i][j] != '\0')
		{
			ft_printf("%c", lines[i][j]);
			j ++;
		}
	}
	(void)map;
	return (1);
}
