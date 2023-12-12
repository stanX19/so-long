#include "so_long.h"

void ft_fill_image(t_image* img, unsigned int color, t_vec2 start, t_vec2 end)
{
	t_vec2 cord;

	cord = start;
	while (cord.y < end.y)
	{
		cord.x = start.x;
		while (cord.x < end.x)
		{
			ft_mlx_pixel_put(img, cord.x, cord.y, color);
			cord.x++;
		}
		cord.y++;
	}

	return ;
}