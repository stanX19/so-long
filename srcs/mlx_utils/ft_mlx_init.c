#include "so_long.h"

t_mlx_data * ft_mlx_init(int window_width, int window_height, char *window_title)
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
    mlx_data->mlx_win = mlx_new_window(mlx_data->mlx, window_width,
										window_height, window_title);
    mlx_data->width = window_width;
    mlx_data->height = window_height;
	mlx_data->all_img.idx = 0;
	mlx_data->all_ani_sprite.idx = 0;

    return mlx_data;
}
