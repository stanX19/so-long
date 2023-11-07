#include "so_long.h"

t_sprite ft_sprite_init(t_image *img, int x, int y, int x_size, int y_size) {
    t_sprite new_sprite;
	
	new_sprite.width = img->width / x_size;
	new_sprite.height = img->height / y_size;
	x *= new_sprite.width;
	y *= new_sprite.height;
    new_sprite.addr = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	new_sprite.line_length = img->line_length;
	new_sprite.bits_per_pixel = img->bits_per_pixel;

    return new_sprite;
}