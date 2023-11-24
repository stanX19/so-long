#include "so_long.h"

t_mlx_data * ft_mlx_init(void)
{
    t_mlx_data * mlx_data;
	mlx_data = malloc(sizeof(t_mlx_data));
	if (!mlx_data)
	{
		ft_printf("mlx init: Failed to malloc");
		return 0;
	}
    mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
	{
		ft_printf("mlx init: Failed to mlx_init()");
		free(mlx_data);
		return 0;
	}
	return mlx_data;
}

t_mlx_data * ft_mlx_win_init(t_mlx_data * mlx_data, int width, int height, char *title)
{	
    mlx_data->mlx_win = mlx_new_window(mlx_data->mlx, width, height, title);
    mlx_data->width = width;
    mlx_data->height = height;

    return mlx_data;
}
