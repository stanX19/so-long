#include "so_long.h"

static void	put_itbl_by_cord(t_image *img, t_vec2 tile_size, t_itbl *itbl)
{
	ft_put_interactable_to_img(img, itbl,
		2 * itbl->loc.x * tile_size.x + itbl->rel_cords.x,
		2 * itbl->loc.y * tile_size.y + itbl->rel_cords.y
	);
}

void	ft_map_put_itbl(t_image *bg, t_map *map)
{
	t_vec2	tile_size;
	size_t	idx;

	tile_size = map->assets->tile_size;
	put_itbl_by_cord(bg, tile_size, map->player1);
	put_itbl_by_cord(bg, tile_size, map->exit);
	idx = 0;
	while (idx < map->coin_len)
	{
		put_itbl_by_cord(bg, tile_size, map->coins[idx++]);
	}
	idx = 0;
	while (idx < map->enemy_len)
	{
		put_itbl_by_cord(bg, tile_size, map->enemy[idx++]);
	}
}