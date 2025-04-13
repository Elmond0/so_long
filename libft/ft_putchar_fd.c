/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:44:56 by elmondo           #+#    #+#             */
/*   Updated: 2025/04/13 16:37:06 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void)
{
	int	file;
	
	file = open("file.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(file == -1)
	{
		printf("Errore apertura file");
		return 1;
	}
	printf("File aperto, file: %d\n", file);
	ft_putchar_fd('A', file);
	close(file);
	return 0;
}
*/
