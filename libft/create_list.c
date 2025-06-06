/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmondo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:28:39 by elmondo           #+#    #+#             */
/*   Updated: 2025/04/13 16:35:55 by elmondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**create_list(int list_size, char **nptr)
{
	t_list	**list;
	t_list	*node;
	int		i;
	int		*arg;

	i = 0;
	list = NULL;
	arg = malloc(sizeof(int));
	if (!arg)
		return (0);
	while (i < list_size)
	{
		*arg = ft_atoi(nptr[i]);
		node = ft_lstnew(arg);
		if (!node)
		{
			ft_lstiter(*list, free);
			return (NULL);
		}
		ft_lstadd_back(list, node);
		i++;
	}
	return (list);
}
