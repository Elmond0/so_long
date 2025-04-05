/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:30:43 by elmondo           #+#    #+#             */
/*   Updated: 2025/04/05 15:25:37 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
#include "libft/libft.h"
#include "mlx/mlx.h"
#include "mlx/mlx_int.h"


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
	void	*c_imgs[6];
	int		coin_pos;
	int		coin_loop;
}	t_coin;

//For Exit (UFO)
typedef struct s_exit
{
	void	*e_imgs[10];
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
}	t_game;

//FT_UTILS
int	ft_check_extention(char *file_name);
void	error_message(int flag);
int	ft_countchar(char *str);
//MAP_INIT
int	map_lines_counter(char *file_path);
int	map_char_counter(char *file_path);
t_game	*map_init(char *file_path);
char	**map_read(char *file_path);
//MAP_VALIDATION
int	map_valid_allrequisites(t_map *map, char *file_path);
int	map_valid_havecharacters(t_map *map);
int	map_valid_isclosed(t_map *map);
int	map_valid_havemustchar(t_map *map);
int	map_valid_haveminsize(t_map *map);
//MAP_VALIDATION2
int	map_valid_havepath(t_map *map, char **map_copy);

//FT_FREE
void	free_dp_char(char **dp_char);
int	flood_fill(char **map, int y, int x);
int	map_valid_havemaxsize(t_map *map);
char	**matrix_dup(t_map *map, char **map_todup);
int	flood_fill_c(char **map, int y, int x);

#endif
