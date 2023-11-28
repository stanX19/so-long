#include "so_long.h"

static int all_dead(t_itbl **arr, int len)
{
	int idx;

	idx = 0;
	while (idx < len)
	{
		if (!(arr[idx++]->status & (DYING | DEAD)))
		{
			return 0;
		}
	}
	return 1;
}

void ft_map_check_reaction(t_map *map, t_vec2 cord)
{
	t_tile val;

	val = map->grid[cord.y][cord.x];
	if ((val & (TILE_PLAYER1 | TILE_COIN)) == (TILE_PLAYER1 | TILE_COIN))
		val &= ~TILE_COIN;
	if ((val & (TILE_PLAYER1 | TILE_EXIT)) == (TILE_PLAYER1 | TILE_EXIT)
		&& all_dead(map->coins, map->coin_len))
		val &= ~TILE_EXIT;
	if ((val & (TILE_PLAYER1 | TILE_ENEMY)) == (TILE_PLAYER1 | TILE_ENEMY))
		val &= ~TILE_PLAYER1;
	if (val & TILE_ATTACKED)
	{
		if (val & TILE_ENEMY)
			val &= ~TILE_ENEMY;
		val &= ~TILE_ATTACKED;
	}
	map->grid[cord.y][cord.x] = val;
}