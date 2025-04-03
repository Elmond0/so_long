/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 15:30:43 by elmondo           #+#    #+#             */
/*   Updated: 2025/04/01 10:52:05 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "mlx/mlx.h"
#include "mlx/mlx_int.h"


#define WID 600
#define LEN 400

typedef	struct s_mlx_img
{
	void	*img_ptr;
	char	*img_pixel_ptr;
	int	bits_for_pixel;
	int	endian;
	int	line_len;
}	t_mlx_img;

typedef	struct s_mlx_data
{
	void	*mlx_ptr;
	void	*mlx_window;
	t_mlx_img	img;
}	t_mlx_data;

int	on_keypress(int keysym, t_mlx_data *data);
int	close_display(t_mlx_data *data);
int	on_leave_window(t_mlx_data *data);
int	on_enter_window(t_mlx_data *data);

#endif
