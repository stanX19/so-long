#include "so_long.h"

t_image* ft_new_image(t_mlx_data* data, int width, int height)
{
	t_image* img;

	img = malloc(sizeof(t_image));
	if (img == 0)
	{
		ft_printf("failed to allocate memory for new image");
		return 0;
	}
	img->width = width;
	img->height = height;
	img->img = mlx_new_image(data->mlx, width, height);
	if (img->img == NULL || ft_add_to_free_arr(&data->all_img, img))
	{
		ft_image_destory(data, img);
		return 0;
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->line_length, &img->endian);

	return img;
}