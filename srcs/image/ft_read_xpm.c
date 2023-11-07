#include "so_long.h"

t_image ft_read_xpm(t_window_data* data, char* relative_path){
	t_image img;

	img.img = mlx_xpm_file_to_image(data->mlx, relative_path, &(img.width), &(img.height));
	img.addr = mlx_get_data_addr(img.img, &(img.bits_per_pixel), &(img.line_length), &(img.endian));
	
	return img;
}