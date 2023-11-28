#include "so_long.h"

static void	m_update_itbl_status(t_map *map, t_itbl *itbl)
{
	if (!(map->grid[itbl->cord.y][itbl->cord.x] & itbl->self))
		itbl->status = DYING;
}

void	ft_map_update_all_status(t_map *map)
{
	size_t	idx;

	m_update_itbl_status(map, map->player1);
	m_update_itbl_status(map, map->exit);
	idx = 0;
	while (idx < map->coin_len)
	{
		m_update_itbl_status(map, map->coins[idx++]);
	}
	idx = 0;
	while (idx < map->enemy_len)
	{
		m_update_itbl_status(map, map->enemy[idx++]);
	}
}