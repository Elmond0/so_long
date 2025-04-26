/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:48:57 by elmondo           #+#    #+#             */
/*   Updated: 2025/04/26 20:48:54 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Check if the ARGV have the .ber at the end and if its a valid file.
//Return 1 if ok, 0 in case dont.
int	ft_check_extention(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (0);
	}
	if (ft_strncmp(file_name + ft_strlen(file_name) - 4, ".ber", 4) != 0)
		return (0);
	close(fd);
	return (1);
}

//Similar to ft_strlen()
//Counts the number of char in a string
//Until it reachs one \n or '\0'
//returns an INT with the number of char counted
int	ft_countchar(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i ++;
	return (i);
}

//For personalizated error messages
void	error_message(int flag, t_game *game)
{
	if (game->error == 3)
		write(2, "Error\n", 6);
	if (flag == 0)
	{
		write(2, "Invalid Sintax\n", 16);
		game->error = 1;
	}
	if (flag == 1)
	{
		write(2, "Couldn't open map file.\n", 24);
		game->error = 1;
		free(game);
	}
	if (flag == 2)
	{
		write(2, "Invalid Map.\n", 13);
		game->error = 1;
	}
	if (flag == 3)
	{
		write(2, "Invalid Map init.\n", 18);
		game->error = 1;
	}
}

void	error_message2(int flag, t_game *game)
{
	if (game->error == 3)
		write(2, "Error\n", 6);
	if (flag == 4)
	{
		write(2, "Invalid Map line.\n", 18);
		game->error = 1;
	}
	if (flag == 5)
	{
		write(2, "Invalid Map - invalid char on map.\n", 36);
		game->error = 1;
	}
	if (flag == 6)
	{
		write(2, "Map not closed.\n", 17);
		game->error = 1;
	}
	if (flag == 7)
	{
		write(2, "No collectables.\n", 17);
		game->error = 1;
	}
}

void	error_message3(int flag, t_game *game)
{
	if (game->error == 3)
		write(2, "Error\n", 6);
	if (flag == 8)
	{
		write(2, "Invalid Map line.\n", 18);
		game->error = 1;
	}
	if (flag == 9)
	{
		write(2, "Invalid Map - invalid char on map.\n", 36);
		game->error = 1;
	}
	if (flag == 10)
	{
		write(2, "Map not closed.\n", 17);
		game->error = 1;
	}
	if (flag == 11)
	{
		write(2, "No collectables.\n", 17);
		game->error = 1;
	}
}
