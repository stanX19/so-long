#include "so_long.h"

t_window * ft_mlx_init(void)
{
    void *	mlx;

    mlx = mlx_init();
	if (!mlx)
	{
		ft_printf("ERROR: Mlx init: Failed to mlx_init()");
	}
	return mlx;
}

