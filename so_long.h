/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:30:43 by elmondo           #+#    #+#             */
/*   Updated: 2025/04/14 12:08:41 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

# define TRUE 1
# define FALSE 0

/* ********************************** */
/*            KEYBOARD CODES          */
/* ********************************** */
# define KB_W 119
# define KB_S 115
# define KB_A 97
# define KB_D 100
# define KB_ESC 65307
# define KB_UP 65362
# define KB_DOWN 65364
# define KB_LEFT 65361
# define KB_RIGHT 65363

//walls
# define FLOOR "textures/sheets/tiles/grass.xpm"
# define MURR "textures/sheets/tiles/walltree.xpm"
# define WALL_BL "textures/sheets/tiles/walltree.xpm"
# define WALL_BR "textures/sheets/tiles/walltree.xpm"
# define WALL_C "textures/sheets/tiles/walltree.xpm"
# define WALL_L "textures/sheets/tiles/walltree.xpm"
# define WALL_ML "textures/sheets/tiles/walltree.xpm"
# define WALL_MR "textures/sheets/tiles/walltree.xpm"
# define WALL_R "textures/sheets/tiles/walltree.xpm"
# define WALL_BC "textures/sheets/tiles/walltree.xpm"
//Player
# define SFRONT "textures/sheets/bunny/stop_front.xpm"
# define SBACK "textures/sheets/bunny/stop_back.xpm"
# define SLEFT "textures/sheets/bunny/stop_left.xpm"
# define SRIGHT "textures/sheets/bunny/stop_right.xpm"
# define WBACK "textures/sheets/bunny/walking_back.xpm"
# define WBACK2 "textures/sheets/bunny/walking_back2.xpm"
# define WFRONT "textures/sheets/bunny/walking_front.xpm"
# define WFRONT2 "textures/sheets/bunny/walking_front2.xpm"
# define WLEFT "textures/sheets/bunny/walking_left.xpm"
# define WLEFT2 "textures/sheets/bunny/walking_left2.xpm"
# define WRIGHT "textures/sheets/bunny/walking_right.xpm"
# define WRIGHT2 "textures/sheets/bunny/walking_right2.xpm"
//Collectable (coin)
# define COIN1 "textures/sheets/coin/coin.xpm"
//Exit
# define EXIT1 "textures/sheets/exit/bunnyhole.xpm"

/* ********************************** */
/*              STRUCTS               */
/* ********************************** */
//For Map
typedef struct s_map
{
	char	**map_skeleton;
	int		qt_lines;
	int		qt_chars_lines;
	int		qt_player;
	int		qt_collect;
	int		qt_exit;
	void	*img_floor;
	void	*img_murr;
	void	*img_wallbl;
	void	*img_wallbr;
	void	*img_wallc;
	void	*img_walll;
	void	*img_wallml;
	void	*img_wallmr;
	void	*img_wallr;
	void	*img_wallbc;
}	t_map;

//For Player
typedef struct s_player
{
	void	*img_sfront;
	void	*img_sback;
	void	*img_sleft;
	void	*img_sright;
	void	*img_wback;
	void	*img_wback2;
	void	*img_wfront;
	void	*img_wfront2;
	void	*img_wleft;
	void	*img_wleft2;
	void	*img_wright;
	void	*img_wright2;
	int		pl_x;
	int		pl_y;
	int		pl_lstep;
	int		pl_rstep;
	int		pl_isonexit;
}	t_player;

//For Collectable (Coin)
typedef struct s_coin
{
	void	*c_imgs[0];
	int		coin_pos;
	int		coin_loop;
}	t_coin;

//For Exit 
typedef struct s_exit
{
	void	*e_imgs[0];
	int		exit_pos;
	int		exit_loop;
	int		exit_yes;
	int		exit_y;
	int		exit_x;
}	t_exit;

//For Mlx
typedef struct s_mlx_data
{
	void	*connect;
	void	*window;
}	t_mlx_data;

//Game main structure
typedef struct s_game
{
	t_map		*map;
	t_mlx_data	*data_mlx;
	t_player	*player;
	t_coin		*coin;
	t_exit		*exit;
	int			img_h;
	int			img_w;
	int			qt_mov;
	int			error;
}	t_game;

//FT_UTILS
int		ft_check_extention(char *file_name);
void	error_message(int flag, t_game *game);
void	error_message2(int flag, t_game *game);
void	error_message3(int flag, t_game *game);
int		ft_countchar(char *str);
//MAP_INIT
int		map_lines_counter(char *file_path, t_game *game);
int		map_char_counter(char *file_path, t_game *game);
t_game	*map_init(char *file_path, t_game *game);
char	**map_read(char *file_path, t_game *game);
//MAP_VALIDATION
int		map_valid_allrequisites(t_map *map, char *file_path, t_game *game);
int		map_valid_havecharacters(t_map *map, t_game *game);
int		map_valid_isclosed(t_map *map, t_game *game);
int		map_valid_havemustchar(t_map *map, t_game *game);
int		map_valid_haveminsize(t_map *map, t_game *game);
//MAP_VALIDATION2
int		map_valid_havepath(t_map *map, char **map_copy);
int		flood_fill(char **map, int y, int x);
int		map_valid_havemaxsiz(t_map *map, t_game *game);
char	**matrix_dup(t_map *map, char **map_todup);
int		flood_fill_c(char **map, int y, int x);
//FT_FREE
void	free_dp_char(char **dp_char);
void	free_coin_imgptr(t_game *game);
void	free_player_imgptr(t_game *game);
void	free_map_imgptr(t_game *game);
void	free_game_struct(t_game *game);

//FREE2
void	free_exit_imgptr(t_game *game);

//GAME_INIT
void	game_init_master(t_game *game);
t_game	*game_init_structs(t_game *game);
void	game_init_values(t_game *game);
//GET_MIMAGES
void	get_mapimg(t_game *game);
void	get_playerimg(t_game *game);
void	get_coinimg(t_game *game);
void	get_exitimg(t_game *game);

//GAME_UTILS
int		game_close(t_game *game);
void	check_nullvalues_pc(t_game *game, char pointers);
void	check_nullvalues_me(t_game *game, char pointers);
int		map_print(t_map *map, char **map_copy);

//GAME_DRAW
int		game_drawmap(t_game *game);
void	draw_mapcorners(t_game *game);
void	draw_mapwallup(t_game *game);
void	draw_mapwallbottom(t_game *game);
//GAME_DRAW2
void	draw_mapwall_left(t_game *game);
void	draw_mapwall_right(t_game *game);
void	draw_mapcenter(t_game *game);
void	draw_mapcoins(t_game *game);
void	draw_exit(t_game *game);
//GAME_RENDER
void	render_elmt(t_game *game, void *img, int width, int height);
void	render_coin(t_game *game, int width, int height);
void	render_exit(t_game *game, int width, int height);
//GAME_PLAY
int		game_play(t_game *game);
void	take_coin(t_game *game, char keypressed);
void	take_coin_lr(t_game *game, int keypressed);
void	take_coin_du(t_game *game, int keypressed);
void	update_tookcoinvalues(t_game *game, int y, int x);
//GAME_KEYPRESSED
int		game_keypressed(int keypressed, t_game *game);
void	key_up_pressed(t_game *game);
void	key_down_pressed(t_game *game);
void	key_left_pressed(t_game *game);
void	key_right_pressed(t_game *game);
//GAME_ANIMATION
int		coin_animation(t_game *game);
int		exit_animation(t_game *game);

#endif
