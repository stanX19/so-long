#include "so_long.h"

static int all_dead(t_map *map, t_itbl **arr, int len)
{
	int idx;
	t_vec2 cord;

	idx = 0;
	while (idx < len)
	{
		cord = arr[idx]->cord;
		if (map->grid[cord.y][cord.x] & arr[idx]->self)
		{
			return 0;
		}
		++idx;
	}
	return 1;
}

void ft_map_check_reaction(t_map *map, t_vec2 cord)
{
	t_tile val;

	val = map->grid[cord.y][cord.x];
	if ((val & (TILE_PLAYER | TILE_COIN)) == (TILE_PLAYER | TILE_COIN))
		val &= ~TILE_COIN;
	if ((val & (TILE_PLAYER | TILE_EXIT)) == (TILE_PLAYER | TILE_EXIT)
		&& all_dead(map, map->coins.arr, map->coins.len))
		val &= ~TILE_EXIT;
	if ((val & (TILE_PLAYER | TILE_SLIME)) == (TILE_PLAYER | TILE_SLIME))
		val &= ~TILE_PLAYER;
	if ((val & (TILE_PLAYER | TILE_BEE)) == (TILE_PLAYER | TILE_BEE))
		val &= ~TILE_PLAYER;
	if (val & TILE_ATTACKED)
	{
		if (val & TILE_SLIME)
			val &= ~TILE_SLIME;
		if (val & TILE_BEE)
			val &= ~TILE_BEE;
		val &= ~TILE_ATTACKED;
	}
	map->grid[cord.y][cord.x] = val;
}