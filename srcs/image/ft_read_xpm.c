#include "so_long.h"


t_image* ft_read_xpm(t_mlx_data* data, char* relative_path){
	t_image* img;
	
	if (!data || !relative_path)
		return 0;
	img = malloc(sizeof(t_image));
	if (!img)
		return 0;
	img->img = mlx_xpm_file_to_image(data->mlx, relative_path, &(img->width), &(img->height));
	if (!img->img || ft_add_to_free_arr(&data->all_img, img))
	{
		ft_image_destory(data, img);
		return 0;
	}
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));

	return img;
}