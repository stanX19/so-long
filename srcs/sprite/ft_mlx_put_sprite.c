#include "so_long.h"

int get_sprite_pixel_color(t_sprite* sprite, int x, int y) {
    char *pixel_ptr = sprite->addr + (y * sprite->line_length + x * (sprite->bits_per_pixel / 8));
    return *(unsigned int*)pixel_ptr;
}

void ft_mlx_put_sprite_reverse(t_image* image, t_sprite* sprite, int img_x, int img_y){
	unsigned int color;

	if (!sprite || !image)
		return ;
	if (!image)
	{
		ft_printf("mlx put sprite: empty base image passed in");
		return ;
	}
    for (int x = 0; x < sprite->width; x++) {
        for (int y = 0; y < sprite->height; y++) {
            color = get_sprite_pixel_color(sprite, sprite->width - x - 1, y);
            ft_mlx_pixel_put(image, img_x + x, img_y + y, color);
        }
    }
}

void ft_mlx_put_sprite(t_image* image, t_sprite* sprite, int img_x, int img_y){
	unsigned int color;

	if (!sprite || !image)
		return ;
	if (!image)
	{
		ft_printf("mlx put sprite: empty base image passed in");
		return ;
	}
    for (int x = 0; x < sprite->width; x++) {
        for (int y = 0; y < sprite->height; y++) {
            color = get_sprite_pixel_color(sprite, x, y);
            ft_mlx_pixel_put(image, img_x + x, img_y + y, color);
        }
    }
}