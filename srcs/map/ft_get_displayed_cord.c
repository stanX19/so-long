#include "so_long.h"

t_vec2 ft_get_displayed_cord(t_vec2 tile_size, t_itbl *itbl)
{
	t_vec2 ret;

	ret.x = 2 * itbl->cord.x * tile_size.x + itbl->offset.x + itbl->rel_cord.x;
	ret.y = 2 * itbl->cord.y * tile_size.y + itbl->offset.y + itbl->rel_cord.y;
	return ret;
}