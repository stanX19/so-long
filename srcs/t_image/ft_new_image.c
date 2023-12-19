#include "so_long.h"

t_image* ft_new_image(t_assets * assets, int width, int height)
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
	img->img = mlx_new_image(assets->mlx, width, height);
	if (img->img == NULL)
	{
		ft_image_destory(img);
		return 0;
	}
	ft_list_add(&assets->all_img, img);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
	img->mlx = assets->mlx;
	return img;
}