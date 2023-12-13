#include "so_long.h"

t_vec2 ft_mlx_get_screen_size(void *mlx)
{
	t_vec2 ret;

	mlx_get_screen_size(mlx, &ret.x, &ret.y);
	return ret;
}