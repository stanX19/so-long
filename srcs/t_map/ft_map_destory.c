#include "so_long.h"

static void	free_itbl_arr(t_itbl **arr, size_t len)
{
	size_t	idx;

	if (arr == NULL)
        return;
	idx = 0;
	while (idx < len)
	{
		ft_itbl_destory(arr[idx++]);
	}
	free(arr);
}

void	ft_map_destory(t_map *map)
{
	ft_free_2d((void **)map->grid, map->grid_size.y);
	ft_itbl_destory(map->player);
	ft_itbl_destory(map->exit);
	free_itbl_arr(map->coins.arr, map->coins.len);
	free_itbl_arr(map->slimes.arr, map->slimes.len);
	free_itbl_arr(map->bees.arr, map->bees.len);
	free(map);
}