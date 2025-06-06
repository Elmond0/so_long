/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 16:45:21 by elmondo           #+#    #+#             */
/*   Updated: 2025/04/14 12:18:56 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Read the map file.
//Returns a double pointer with the map content stored on it.
char	**map_read(char *file_path, t_game *game)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;

	fd = open(file_path, O_RDONLY);
	map = ft_calloc(sizeof(char *), map_lines_counter(file_path, game) + 1);
	if (!map)
		return (NULL);
	i = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(fd);
	return (map);
}

//Count how many lines
//exist on the map file.
//returns an integer with the nbr of lines.
int	map_lines_counter(char *file_path, t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		error_message(1, game);
		return (-1);
	}
	i = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i ++;
	}
	free(line);
	close(fd);
	return (i);
}

//Counts the number of chars in the strings
//uses ft_countchar() instead of ft_strlen() because
//we need to take \n in consideration.
//returns an INT with the first_line_size.
//if there is some line that the size is != to the first, return error -1.
int	map_char_counter(char *file_path, t_game *game)
{
	char	**map;
	int		i;
	int		first_line_size;

	map = map_read(file_path, game);
	first_line_size = ft_countchar(map[0]);
	if (first_line_size == 0)
	{
		free_dp_char(map);
		return (-1);
	}
	i = 1;
	while (map[i] != NULL)
	{
		if (ft_countchar(map[i]) != first_line_size)
		{
			error_message2(4, game);
			ft_printf("Line %i invalid\n", i + 1);
			free_dp_char(map);
			return (-1);
		}
		i ++;
	}
	free_dp_char(map);
	return (first_line_size);
}

//init the map structure with values
//that we took from other functions
//returns the map structure filled with values.
t_game	*map_init(char *file_path, t_game *game)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (error_message(3, game), NULL);
	game->map = map;
	game->map->map_skeleton = map_read(file_path, game);
	game->map->qt_lines = map_lines_counter(file_path, game);
	game->map->qt_chars_lines = map_char_counter(file_path, game);
	if (game->map->qt_chars_lines == -1)
	{
		error_message(3, game);
		free_dp_char(game->map->map_skeleton);
		free(map);
		free(game);
		exit(EXIT_FAILURE);
	}
	game->map->qt_player = 0;
	game->map->qt_collect = 0;
	game->map->qt_exit = 0;
	return (game);
}
