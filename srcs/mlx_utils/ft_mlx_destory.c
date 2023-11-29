#include "so_long.h"

void	ft_mlx_destory(t_mlx_data * data)
{
	if (data == 0)
	{
		ft_printf("WARNING: mlx destory: null pointer passed in");
		return ;
	}
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->mlx);
	free(data);
}

void	ft_mlx_destory_win(t_mlx_data * data)
{
	if (data == 0)
	{
		ft_printf("WARNING: mlx destory win: null pointer passed in");
		return ;
	}
	mlx_destroy_window(data->mlx, data->mlx_win);
	data->mlx_win = 0;
	data->height = 0;
	data->width = 0;
}