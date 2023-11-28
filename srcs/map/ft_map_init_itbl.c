#include "so_long.h"
#define STORE_SIZE 4

typedef struct s_itbl_iv
{
	t_ani_sprite ***sprite_tab;
	int len;
	t_vec2 offset;
	t_tile self;
	t_tile blocking;
} s_itbl_iv;

static t_itbl	*init_itbl_with_rel(const s_itbl_iv *params)
{
	t_itbl *ret;

	ret = ft_init_interactable(params->sprite_tab);
	ret->offset = params->offset;
	ret->self = params->self;
	ret->blocking = params->blocking;
	return ret;
}

static t_itbl **init_itbl_arr(const s_itbl_iv *params)
{
	t_itbl **ret;
	int idx;

	if (params->len == 0)
		return NULL;

	ret = (t_itbl **)malloc(sizeof(t_itbl*) * (params->len + 1));
	idx = 0;
	while (idx < params->len)
	{
		ret[idx++] = init_itbl_with_rel(params);
	}
	ret[idx] = NULL;
	return ret;
}

void ft_map_init_itbl(t_map *map, t_assets *assets)
{
	s_itbl_iv params;
	
	params = (s_itbl_iv){ assets->coin, map->coin_len, {0, 0}, TILE_COIN, TILE_WALL | TILE_WATER };
	map->coins = init_itbl_arr(&params);
	params = (s_itbl_iv){ assets->player, 1, {-24, -32}, TILE_PLAYER1, TILE_WALL | TILE_WATER };
	map->player1 = init_itbl_with_rel(&params);
	map->player1->stats.base_speed = 1;
	params = (s_itbl_iv){ assets->exit, 1, {-4, -8}, TILE_EXIT, TILE_WALL | TILE_WATER };
	map->exit = init_itbl_with_rel(&params);
	params = (s_itbl_iv){ assets->enemy, map->enemy_len, {-16, -16}, TILE_ENEMY, TILE_WALL | TILE_WATER };
	map->enemy = init_itbl_arr(&params);
}