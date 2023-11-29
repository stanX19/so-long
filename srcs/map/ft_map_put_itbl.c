#include "so_long.h"

static void	put_itbl_by_cord(t_image *img, t_vec2 tile_size, t_itbl *itbl)
{
	if (itbl->status & (DEAD))
		return ;
	ft_put_interactable_to_img(img, itbl,
		2 * itbl->cord.x * tile_size.x + itbl->offset.x + itbl->rel_cord.x,
		2 * itbl->cord.y * tile_size.y + itbl->offset.y + itbl->rel_cord.y
	);
}

void	ft_map_put_itbl(t_image *bg, t_map *map)
{
	t_vec2	tile_size;
	size_t	idx;

	tile_size = map->assets->tile_size;
	idx = 0;
	while (idx < map->coin_len)
	{
		put_itbl_by_cord(bg, tile_size, map->coins[idx++]);
	}
	put_itbl_by_cord(bg, tile_size, map->exit);
	idx = 0;
	while (idx < map->enemy_len)
	{
		put_itbl_by_cord(bg, tile_size, map->enemy[idx++]);
	}
	put_itbl_by_cord(bg, tile_size, map->player1);
}