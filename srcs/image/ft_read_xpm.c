#include "so_long.h"

 static inline t_image * null_with_message(char * message)
{
	ft_printf("ERROR: Read xpm: %s\n", message);
	return 0;
}

t_image* ft_read_xpm(t_mlx_data* data, char* relative_path){
	t_image* img;
	
	if (!data || !relative_path)
		return null_with_message("null pointer received");
	img = malloc(sizeof(t_image));
	if (!img)
		return null_with_message("failed to malloc");
	img->img = mlx_xpm_file_to_image(data->mlx, relative_path, &(img->width), &(img->height));
	if (!img->img)
	{
		free(img);
		return null_with_message(strerror(errno));
	}
	if (ft_add_to_free_arr(&data->all_img, img))
	{
		ft_image_destory(data, img);
		return null_with_message("failed to add img to free array");
	}
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));

	return img;
}