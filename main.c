#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc == 2 && ft_check_extention(argv[1]) == 1)
	{
		game = map_init(argv[1]);
		if (map_valid_allrequisites(game->map, argv[1]))
		{
			ft_printf("OK");
		}
	}
	else
		error_message(1);
	
	return (0);
}
