#include "so_long.h"

void	ft_mlx_pixel_put(t_window_data *window_data, int x, int y, int color)
{
	char	*dst;

	dst = window_data->addr + (y * window_data->line_length + x * (window_data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}