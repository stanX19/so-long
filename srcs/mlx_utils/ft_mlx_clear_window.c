#include "so_long.h"

void ft_mlx_clear_window(t_window *window)
{
	mlx_clear_window(window->mlx, window->mlx_win);
}