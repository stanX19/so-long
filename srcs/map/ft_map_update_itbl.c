#include "so_long.h"

void	ft_map_update_itbl(t_map *map)
{
	size_t	idx;

	ft_update_itbl_status(map->player1);
	ft_update_itbl_status(map->exit);
	idx = 0;
	while (idx < map->coin_len)
	{
		ft_update_itbl_status(map->coins[idx++]);
	}
	idx = 0;
	while (idx < map->enemy_len)
	{
		ft_update_itbl_status(map->enemy[idx++]);
	}
}