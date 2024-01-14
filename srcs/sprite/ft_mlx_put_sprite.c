#include "so_long.h"

int get_sprite_pixel_color(t_sprite* sprite, int x, int y) {
    char *pixel_ptr = sprite->addr + (y * sprite->line_length + x * (sprite->bits_per_pixel / 8));
    return *(unsigned int*)pixel_ptr;
}

void ft_mlx_put_sprite_reverse(t_image* image, t_sprite* sprite, int img_x, int img_y){
	unsigned int color;
	t_vec2 cord;

	if (!sprite || !image)
		return ;
	if (!image)
	{
		ft_printf("mlx put sprite: empty base image passed in");
		return ;
	}
    cord.x = (img_x > 0)? 0: -img_x;
	while (cord.x < min(sprite->width, image->width - img_x))
	{
		cord.y = (img_y > 0)? 0: -img_y;
		while(cord.y < min(sprite->height, image->height - img_y))
		{
            color = get_sprite_pixel_color(sprite, sprite->width - cord.x - 1, cord.y);
            ft_mlx_pixel_put(image, img_x + cord.x, img_y + cord.y, color);
			++cord.y;
		}
		++cord.x;
	}
}

void ft_mlx_put_sprite(t_image* image, t_sprite* sprite, int img_x, int img_y){
	unsigned int color;
	t_vec2 cord;

	if (!sprite || !image)
		return ;
	if (!image)
	{
		ft_printf("mlx put sprite: empty base image passed in");
		return ;
	}
	else if (!sprite)
	{
		ft_printf("mlx put sprite: empty base image passed in");
		return ;
	}
	cord.x = (img_x > 0)? 0: -img_x;
	while (cord.x < min(sprite->width, image->width - img_x))
	{
		cord.y = (img_y > 0)? 0: -img_y;
		while(cord.y < min(sprite->height, image->height - img_y))
		{
			color = get_sprite_pixel_color(sprite, cord.x, cord.y);
			ft_mlx_pixel_put(image, img_x + cord.x, img_y + cord.y, color);
			++cord.y;
		}
		++cord.x;
	}
}