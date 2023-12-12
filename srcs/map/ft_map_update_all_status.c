#include "so_long.h"

static void	m_update_itbl_status(t_map *map, t_itbl *itbl)
{
	if (!(map->grid[itbl->cord.y][itbl->cord.x] & itbl->self)
		&& !(itbl->status & (DYING | DEAD)))
	{
		ft_itbl_set_status(itbl, DYING);
	}
}

static void m_update_arr(t_map *map, t_itbl_arr itbl_arr)
{
	size_t	idx;

	idx = -1;
	while (++idx < itbl_arr.len)
	{
		m_update_itbl_status(map, itbl_arr.arr[idx]);
	}
}

void	ft_map_update_all_status(t_map *map)
{

	m_update_itbl_status(map, map->player);
	m_update_itbl_status(map, map->exit);
	m_update_arr(map, map->coins);
	m_update_arr(map, map->slimes);
	m_update_arr(map, map->bees);
}