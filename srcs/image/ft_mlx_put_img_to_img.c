#include "so_long.h"

int get_img_pixel_color(t_image *img, int x, int y) {
    char *pixel_ptr = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    return *(unsigned int*)pixel_ptr;
}

void ft_mlx_put_img_to_img(t_image* dst, t_image* src, int img_x, int img_y)
{
	unsigned int color;
	int x;
	int y;

	if (!dst || !src)
		return ;
	x = (img_x > 0)? 0: -img_x;
	while (x < min(src->width, dst->width - img_x + 1))
	{
		y = (img_y > 0)? 0: -img_y;
		while(y < min(src->height, dst->height - img_y + 1))
		{
			
			color = get_img_pixel_color(src, x, y);
			ft_mlx_pixel_put(dst, img_x + x, img_y + y, color);
			++y;
		}
		++x;
	}
}