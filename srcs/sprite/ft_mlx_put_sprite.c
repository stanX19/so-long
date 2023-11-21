#include "so_long.h"

int get_sprite_pixel_color(t_sprite* sprite, int x, int y) {
    char *pixel_ptr = sprite->addr + (y * sprite->line_length + x * (sprite->bits_per_pixel / 8));
    return *(unsigned int*)pixel_ptr;
}

void ft_mlx_put_sprite_reverse(t_image* image, t_sprite* sprite, int img_x, int img_y){
	unsigned int color;
	int x;
	int y;

	if (!sprite || !image)
		return ;
	if (!image)
	{
		ft_printf("mlx put sprite: empty base image passed in");
		return ;
	}
    x = (img_x > 0)? 0: -img_x;
	while (x < min(sprite->width, image->width - img_x))
	{
		y = (img_y > 0)? 0: -img_y;
		while(y < min(sprite->height, image->height - img_y))
		{
            color = get_sprite_pixel_color(sprite, sprite->width - x - 1, y);
            ft_mlx_pixel_put(image, img_x + x, img_y + y, color);
			++y;
		}
		++x;
	}
}

void ft_mlx_put_sprite(t_image* image, t_sprite* sprite, int img_x, int img_y){
	unsigned int color;
	int x;
	int y;

	if (!sprite || !image)
		return ;
	if (!image)
	{
		ft_printf("mlx put sprite: empty base image passed in");
		return ;
	}
	x = (img_x > 0)? 0: -img_x;
	while (x < min(sprite->width, image->width))
	{
		y = (img_y > 0)? 0: -img_y;
		while(y < min(sprite->height, image->height))
		{
			color = get_sprite_pixel_color(sprite, x, y);
			ft_mlx_pixel_put(image, img_x + x, img_y + y, color);
			++y;
		}
		++x;
	}
}