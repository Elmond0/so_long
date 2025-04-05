#include "so_long.h"

void	free_dp_char(char **dp_char)
{
	int	i;

	i = 0;
	if (!dp_char)
		return ;
	while (dp_char[i])
	{
		free(dp_char[i]);
		i ++;
	}
	free(dp_char);
}
