#include "so_long.h"

void	ft_mlx_pixel_put(t_image* img, int x, int y, unsigned int color)
{
	char	*dst;
	t_color	clrA;
	t_color clrB;
	
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));

	clrA.trgb = color;
	clrA.t = 1;
	clrB.trgb = *(unsigned int*)dst;

	clrB.t = (char)0;
	clrB.r = (char)((((int)clrA.r * ((int)255 - clrA.t)) + ((int)clrB.r * (int)clrA.t)) / 255);
	clrB.g = (char)((((int)clrA.g * ((int)255 - clrA.t)) + ((int)clrB.g * (int)clrA.t)) / 255);
	clrB.b = (char)((((int)clrA.b * ((int)255 - clrA.t)) + ((int)clrB.b * (int)clrA.t)) / 255);
	*(unsigned int*)dst = clrB.trgb;
}