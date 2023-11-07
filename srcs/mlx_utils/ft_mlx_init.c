#include "so_long.h"

t_window_data ft_mlx_init(int window_width, int window_height, char *window_title) {
    t_window_data window_data;

    window_data.mlx = mlx_init();
    window_data.mlx_win = mlx_new_window(window_data.mlx, window_width, window_height, window_title);
    window_data.width = window_width;
    window_data.height = window_height;

    return window_data;
}
