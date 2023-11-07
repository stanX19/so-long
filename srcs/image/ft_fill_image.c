#include "so_long.h"

void ft_fill_image(t_image* img, int color) {
	for (int x = 0; x < img->width; x++) {
		for (int y = 0; y < img->height; y++) {
			ft_mlx_pixel_put(img, x, y, color);
		}
	}

	return ;
}