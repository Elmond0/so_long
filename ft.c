#include "so_long.h"

int	close_display(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(EXIT_SUCCESS);
}
void	color_screen(t_mlx_data *data, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < LEN)
	{
		x = 0 ;
		while (x < WID)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_window, x, y, color);
			x++;
		}
		y++;
	}
}

int	on_keypress(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
		close_display(data);
	else if (keysym == XK_r)
		color_screen(data, 0xff0000);
	else if (keysym == XK_g)
		color_screen(data, 0xff00);
	else if (keysym == XK_b)
		color_screen(data, 0xff);
	printf("Key %d has been pressed\n", keysym);
	return (0);
}
int	on_leave_window(t_mlx_data *data)
{
	(void)data;
	write(1, "Bye\n", 4);
	return (0);
}
int	on_enter_window(t_mlx_data *data)
{
	(void)data;
	write(1, "Welcome\n", 8);
	return (0);
}
