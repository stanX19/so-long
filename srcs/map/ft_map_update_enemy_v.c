#include "so_long.h"

static void	update_arr_v(t_itbl_arr itbl_arr)
{
	size_t i;

	i = 0;
	while (i < itbl_arr.len)
	{
		itbl_arr.arr[i]->velocity.x += rand() % 3 - 1;
		itbl_arr.arr[i]->velocity.y += rand() % 3 - 1;
		itbl_arr.arr[i]->status |= MOVING;
		++i;
	}
}

void	ft_map_update_enemy_v(t_map *map)
{
	update_arr_v(map->slimes);
	update_arr_v(map->bees);
}