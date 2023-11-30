#include "so_long.h"

int ft_mlx_put_image_to_win(t_window* window, t_image* img, int x, int y){
	return mlx_put_image_to_window(window->mlx, window->mlx_win, img->img, x, y);
}