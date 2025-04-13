/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:43:53 by elmondo           #+#    #+#             */
/*   Updated: 2025/04/13 16:43:53 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_exit_imgptr(t_game *game)
{
	t_mlx_data	*connect;

	connect = game->data_mlx->connect;
	mlx_destroy_image(connect, game->exit->e_imgs[0]);
}
