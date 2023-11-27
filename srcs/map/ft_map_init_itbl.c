#include "so_long.h"
#define STORE_SIZE 4

static t_itbl	*init_itbl_with_rel(t_ani_sprite ***sprite_tab, t_vec2 offset, t_tile blocking)
{
	t_itbl *ret;

	ret = ft_init_interactable(sprite_tab);
	ret->offset = offset;
	ret->blocking = blocking;
	return ret;
}

static t_itbl **init_itbl_arr(t_ani_sprite ***sprite_tab, int len, t_vec2 offset, t_tile blocking)
{
	t_itbl **ret;
	int idx;

	if (len == 0)
		return 0;
	ret = (t_itbl **)malloc(sizeof(t_itbl*) * (len + 1));
	idx = 0;
	while (idx < len)
	{
		ret[idx++] = init_itbl_with_rel(sprite_tab, offset, blocking);
	}
	ret[idx] = 0;
	return (ret);
}

void	ft_map_init_itbl(t_map *map, t_assets *assets)
{
	t_vec2	offset;
	t_tile	blocking;

	offset = (t_vec2){0, 0};
	blocking = (WALL | WATER);
	map->coins = init_itbl_arr(assets->coin, map->coin_len, offset, blocking);
	offset = (t_vec2){-24, -32};
	map->player1 = init_itbl_with_rel(assets->player, offset, blocking);
	offset = (t_vec2){-16, -16};
	map->exit = init_itbl_with_rel(assets->exit, offset, blocking);
	map->enemy = init_itbl_arr(assets->enemy, map->enemy_len, offset, blocking);
}