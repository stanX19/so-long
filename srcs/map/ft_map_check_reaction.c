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
	if ((val & (PLAYER1 | COIN)) == (PLAYER1 | COIN))
		val &= ~COIN;
	if ((val & (PLAYER1 | EXIT)) == (PLAYER1 | EXIT)
		&& all_dead(map->coins, map->coin_len))
		val &= ~EXIT;
	map->grid[cord.y][cord.x] = val;
}