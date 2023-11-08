#include "so_long.h"

t_image* ft_new_image(t_window_data* data, int width, int height){
	t_image* img;

	img = malloc(sizeof(t_image));
	img->width = width;
	img->height = height;
	img->img = mlx_new_image(data->mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);

	return img;
}