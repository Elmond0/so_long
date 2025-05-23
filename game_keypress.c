/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_keypress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:40:53 by elmondo           #+#    #+#             */
/*   Updated: 2025/04/13 16:40:53 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_keypressed(int keypressed, t_game *game)
{
	if (keypressed == KB_ESC)
		game_close(game);
	else if ((keypressed == KB_W || keypressed == KB_UP)
		&& game->player->pl_isonexit == FALSE)
		key_up_pressed(game);
	else if ((keypressed == KB_S || keypressed == KB_DOWN)
		&& game->player->pl_isonexit == FALSE)
		key_down_pressed(game);
	else if ((keypressed == KB_A || keypressed == KB_LEFT)
		&& game->player->pl_isonexit == FALSE)
		key_left_pressed(game);
	else if ((keypressed == KB_D || keypressed == KB_RIGHT)
		&& game->player->pl_isonexit == FALSE)
		key_right_pressed(game);
	if (game->exit->exit_x == game->player->pl_x
		&& game->exit->exit_y == game->player->pl_y
		&& game->exit->exit_yes == TRUE && game->player->pl_isonexit == FALSE)
	{
		game->player->pl_isonexit = TRUE;
		ft_printf("YOU WIN\n");
	}
	if (game->player->pl_isonexit == FALSE)
		ft_printf("Quantity of moves %i\n", game->qt_mov);
	return (0);
}

//Make the player go up one tile.
//W and UP Arrow are up keys.
//Magic -1 is for render player on the y -1 position of map
void	key_up_pressed(t_game *game)
{
	t_player	*pl;
	t_map		*mp;
	char		**map_sk;

	pl = game->player;
	mp = game->map;
	map_sk = game->map->map_skeleton;
	if (map_sk[pl->pl_y - 1][pl->pl_x] == 'C')
		take_coin(game, 'u');
	else if (map_sk[pl->pl_y - 1][pl->pl_x] != '1' && pl->pl_lstep == FALSE)
	{
		game->player->pl_y --;
		render_elmt(game, mp->img_floor, 32 * pl->pl_x, 32 * (pl->pl_y + 1));
		render_elmt(game, pl->img_wback, 32 * pl->pl_x, 32 * pl->pl_y);
		pl->pl_lstep = TRUE;
		game->qt_mov++;
	}
	else if (map_sk[pl->pl_y - 1][pl->pl_x] != '1' && pl->pl_lstep == TRUE)
	{
		game->player->pl_y --;
		render_elmt(game, mp->img_floor, 32 * pl->pl_x, 32 * (pl->pl_y + 1));
		render_elmt(game, pl->img_wback2, 32 * pl->pl_x, 32 * pl->pl_y);
		pl->pl_lstep = FALSE;
		game->qt_mov++;
	}
}

//Function to make the player go down one
//S and DOWN Arrow are up keys.
void	key_down_pressed(t_game *game)
{
	t_player	*pl;
	t_map		*mp;
	char		**map_sk;

	pl = game->player;
	mp = game->map;
	map_sk = game->map->map_skeleton;
	if (map_sk[pl->pl_y + 1][pl->pl_x] == 'C')
		take_coin(game, 'd');
	else if (map_sk[pl->pl_y + 1][pl->pl_x] != '1' && pl->pl_lstep == FALSE)
	{
		game->player->pl_y ++;
		render_elmt(game, mp->img_floor, 32 * pl->pl_x, 32 * (pl->pl_y - 1));
		render_elmt(game, pl->img_wfront, 32 * pl->pl_x, 32 * pl->pl_y);
		pl->pl_lstep = TRUE;
		game->qt_mov++;
	}
	else if (map_sk[pl->pl_y + 1][pl->pl_x] != '1' && pl->pl_lstep == TRUE)
	{
		game->player->pl_y ++;
		render_elmt(game, mp->img_floor, 32 * pl->pl_x, 32 * (pl->pl_y - 1));
		render_elmt(game, pl->img_wfront2, 32 * pl->pl_x, 32 * pl->pl_y);
		pl->pl_lstep = FALSE;
		game->qt_mov++;
	}
}

//Function to make the player go left one
//A and LEFT Arrow are left keys.
void	key_left_pressed(t_game *game)
{
	t_player	*pl;
	t_map		*mp;
	char		**map_sk;

	pl = game->player;
	mp = game->map;
	map_sk = game->map->map_skeleton;
	if (map_sk[pl->pl_y][pl->pl_x - 1] == 'C')
		take_coin(game, 'l');
	else if (map_sk[pl->pl_y][pl->pl_x - 1] != '1' && pl->pl_lstep == FALSE)
	{
		game->player->pl_x --;
		render_elmt(game, mp->img_floor, 32 * (pl->pl_x + 1), 32 * pl->pl_y);
		render_elmt(game, pl->img_wleft, 32 * pl->pl_x, 32 * pl->pl_y);
		pl->pl_lstep = TRUE;
		game->qt_mov++;
	}
	else if (map_sk[pl->pl_y][pl->pl_x - 1] != '1' && pl->pl_lstep == TRUE)
	{
		game->player->pl_x --;
		render_elmt(game, mp->img_floor, 32 * (pl->pl_x + 1), 32 * pl->pl_y);
		render_elmt(game, pl->img_wleft2, 32 * pl->pl_x, 32 * pl->pl_y);
		pl->pl_lstep = FALSE;
		game->qt_mov++;
	}
}

//Function to make the player go right one
//S and RIGHT_ARROW are right keys.
void	key_right_pressed(t_game *game)
{
	t_player	*pl;
	t_map		*mp;
	char		**map_sk;

	pl = game->player;
	mp = game->map;
	map_sk = game->map->map_skeleton;
	if (map_sk[pl->pl_y][pl->pl_x + 1] == 'C')
		take_coin(game, 'r');
	else if (map_sk[pl->pl_y][pl->pl_x + 1] != '1' && pl->pl_lstep == FALSE)
	{
		game->player->pl_x ++;
		render_elmt(game, mp->img_floor, 32 * (pl->pl_x - 1), 32 * pl->pl_y);
		render_elmt(game, pl->img_wright, 32 * pl->pl_x, 32 * pl->pl_y);
		pl->pl_lstep = TRUE;
		game->qt_mov++;
	}
	else if (map_sk[pl->pl_y][pl->pl_x + 1] != '1' && pl->pl_lstep == TRUE)
	{
		game->player->pl_x ++;
		render_elmt(game, mp->img_floor, 32 * (pl->pl_x - 1), 32 * pl->pl_y);
		render_elmt(game, pl->img_wright2, 32 * pl->pl_x, 32 * pl->pl_y);
		pl->pl_lstep = FALSE;
		game->qt_mov++;
	}
}
