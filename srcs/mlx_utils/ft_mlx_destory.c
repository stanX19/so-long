#include "so_long.h"

void	ft_mlx_destory(void *mlx)
{
	if (mlx == 0)
	{
		ft_printf("WARNING: mlx destory: null pointer passed in");
		return ;
	}
	free(mlx);
}

