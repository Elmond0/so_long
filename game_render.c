/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:43:42 by elmondo           #+#    #+#             */
/*   Updated: 2025/04/13 16:44:07 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Render the elements tiles
void	render_elmt(t_game *game, void *img, int width, int height)
{
	t_mlx_data	*conn;
	t_mlx_data	*wnd;

	conn = game->data_mlx->connect;
	wnd = game->data_mlx->window;
	mlx_put_image_to_window(conn, wnd, img, width, height);
}

//render the element coin according to the position
//coint is separate from general render_elements() because
//it has animation
void	render_coin(t_game *game, int width, int height)
{
	t_mlx_data	*conn;
	t_mlx_data	*wnd;
	t_coin		*gc;

	conn = game->data_mlx->connect;
	wnd = game->data_mlx->window;
	gc = game->coin;
	mlx_put_image_to_window(conn, wnd, gc->c_imgs[0], width, height);
}

void	render_exit(t_game *game, int width, int height)
{
	t_mlx_data	*conn;
	t_mlx_data	*wnd;
	t_exit		*ge;

	conn = game->data_mlx->connect;
	wnd = game->data_mlx->window;
	ge = game->exit;
	if (ge->exit_yes == FALSE)
		mlx_put_image_to_window(conn, wnd, game->map->img_floor, width, height);
	if (ge->exit_yes == TRUE)
		mlx_put_image_to_window(conn, wnd, ge->e_imgs[0], width, height);
}
