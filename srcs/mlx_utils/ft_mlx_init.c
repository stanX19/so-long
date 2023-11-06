#include "so_long.h"

t_window_data ft_mlx_init(int window_width, int window_height, char *window_title) {
    t_window_data window_data;

    // Initialize the MiniLibX context
    window_data.mlx = mlx_init();
    window_data.mlx_win = mlx_new_window(window_data.mlx, window_width, window_height, window_title);
    window_data.img = mlx_new_image(window_data.mlx, window_width, window_height);
    window_data.addr = mlx_get_data_addr(window_data.img, &window_data.bits_per_pixel, &window_data.line_length, &window_data.endian);

    // Get information about the window
    window_data.width = window_width;
    window_data.height = window_height;

    // You can set other fields to their default values here
    return window_data;
}
