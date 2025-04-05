/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:01:49 by miricci           #+#    #+#             */
/*   Updated: 2025/04/05 10:01:06 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		i += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr == -2147483648)
	{
		ft_putstr("2147483648");
		return (11);
	}
	if (nbr >= 10)
	{
		i += ft_putnbr(nbr / 10);
	}
	nbr = (nbr % 10) + 48;
	i += ft_putchar(nbr);
	return (i);
}
/*
int	main()
{
	ft_putnbr(-2147483648);
	return 0;
}
*/