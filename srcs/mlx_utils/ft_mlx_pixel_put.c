#include "so_long.h"

void	ft_mlx_pixel_put(t_image* img, int x, int y, unsigned int color)
{
	char	*dst;
	t_color	clrA;
	t_color clrB;
	
	// #include <assert.h>
	// assert(x < img->width);
	// assert(y < img->height);
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));

	clrA.trgb = color;
	clrB.trgb = *(unsigned int*)dst;

	clrB.t = (char)0;
	clrB.r = (char)(((clrA.r * (255 - clrA.t)) + (clrB.r * clrA.t)) / 255);
	clrB.g = (char)(((clrA.g * (255 - clrA.t)) + (clrB.g * clrA.t)) / 255);
	clrB.b = (char)(((clrA.b * (255 - clrA.t)) + (clrB.b * clrA.t)) / 255);

	*(unsigned int*)dst = clrB.trgb;
}