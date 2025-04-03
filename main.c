#include "so_long.h"

int	main(void)
{
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.mlx_window = mlx_new_window(data.mlx_ptr, 600, 400, "Eccomi");
	mlx_key_hook(data.mlx_window, on_keypress, &data);
	mlx_hook(data.mlx_window, DestroyNotify, NoEventMask, close_display, &data);
	mlx_hook(data.mlx_window, LeaveNotify, LeaveWindowMask, on_leave_window, &data);
	mlx_hook(data.mlx_window, EnterNotify, EnterWindowMask, on_enter_window, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.mlx_window);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	
	return (0);
}