#include "so_long.h"

static void	put_itbl_by_cord(t_image *img, t_vec2 tile_size, t_itbl *itbl)
{
	if (itbl->status & DEAD)
		return ;
	ft_put_interactable_to_img(img, itbl,
		2 * itbl->cord.x * tile_size.x + itbl->offset.x + itbl->rel_cord.x,
		2 * itbl->cord.y * tile_size.y + itbl->offset.y + itbl->rel_cord.y
	);
}

static void	put_itbl_arr(t_image *img, t_vec2 tile_size, t_itbl_arr itbl_arr)
{
	size_t	idx;

	idx = 0;
	while (idx < itbl_arr.len)
	{
		put_itbl_by_cord(img, tile_size, itbl_arr.arr[idx++]);
	}
}

void	ft_map_put_itbl(t_image *img, t_map *map)
{
	t_vec2	tile_size;

	tile_size = map->assets->tile_size;
	put_itbl_arr(img, tile_size, map->coins);
	put_itbl_by_cord(img, tile_size, map->exit);
	put_itbl_arr(img, tile_size, map->slimes);
	put_itbl_arr(img, tile_size, map->bees);
	put_itbl_by_cord(img, tile_size, map->player1);
}