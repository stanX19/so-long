#include "so_long.h"

static t_itbl	*init_itbl(t_itbl* src, t_tile self)
{
	t_itbl *ret;

	ret = ft_itbl_copy(src);
	ft_set_itbl_settings(ret, self);
	return ret;
}

static t_itbl **init_itbl_arr(t_itbl* src, int len, t_tile self)
{
	t_itbl **ret;
	int idx;

	ret = (t_itbl **)malloc(sizeof(t_itbl*) * (len + 1));
	if (!ret)
	{
		ft_printf("ERROR: Init itbl arr: failed to malloc\n");
		return 0;
	}
	idx = 0;
	if (idx < len)
	{
		ret[idx++] = init_itbl(src, self);
	}
	while (idx < len)
	{
		ret[idx++] = ft_itbl_copy(ret[0]);
	}
	ret[idx] = 0;
	return ret;
}

void ft_map_init_itbl(t_map *map, t_assets *assets)
{
	map->player = init_itbl(assets->player, TILE_PLAYER);
	map->exit = init_itbl(assets->cat, TILE_EXIT);
	map->slimes.arr = init_itbl_arr(assets->slime, map->slimes.len, TILE_SLIME);
	map->bees.arr = init_itbl_arr(assets->bee, map->bees.len, TILE_BEE);
	map->coins.arr = init_itbl_arr(assets->coin, map->coins.len, TILE_COIN);
}