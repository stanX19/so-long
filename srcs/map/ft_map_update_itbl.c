#include "so_long.h"

static void	update_arr(t_itbl_arr itbl_arr)
{
	size_t idx;
	
	idx = -1;
	while (++idx < itbl_arr.len)
	{
		ft_update_itbl_status(itbl_arr.arr[idx]);
	}
}

void	ft_map_update_itbl(t_map *map)
{
	ft_update_itbl_status(map->player1);
	ft_update_itbl_status(map->exit);
	update_arr(map->slimes);
	update_arr(map->bees);
	update_arr(map->coins);
}