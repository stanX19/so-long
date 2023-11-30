#include "so_long.h"

t_window * ft_window_init(void * mlx, int width, int height, char *title)
{	
	t_window * window;

	window = malloc(sizeof(t_window));
	if (!window)
	{
		ft_printf("ERROR: Window init: Failed to malloc");
		return 0;
	}
	window->mlx = mlx;
    window->mlx_win = mlx_new_window(mlx, width, height, title);
	window->title = title;
    window->width = width;
    window->height = height;
    return window;
}