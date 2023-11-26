#include "so_long.h"
#define STORE_SIZE 4

static t_itbl	*init_itbl_with_rel(t_ani_sprite ***sprite_tab, t_vec2 rel_cords)
{
	t_itbl *ret;

	ret = ft_init_interactable(sprite_tab);
	ret->rel_cords = rel_cords;
	return ret;
}

static t_itbl **init_itbl_arr(t_ani_sprite ***sprite_tab, int len, t_vec2 rel_cords)
{
	t_itbl **ret;
	int idx;

	if (len == 0)
		return 0;
	ret = (t_itbl **)malloc(sizeof(t_itbl*) * (len + 1));
	idx = 0;
	while (idx < len)
	{
		ret[idx++] = init_itbl_with_rel(sprite_tab, rel_cords);
	}
	ret[idx] = 0;
	return (ret);
}

void	ft_map_init_itbl(t_map *map, t_assets *assets)
{
	t_vec2 rel_cords;

	rel_cords = (t_vec2){0, 0};
	map->coins = init_itbl_arr(assets->coin, map->coin_len, rel_cords);
	rel_cords = (t_vec2){-24, -32};
	map->player1 = init_itbl_with_rel(assets->player, rel_cords);
	rel_cords = (t_vec2){-16, -16};
	map->exit = init_itbl_with_rel(assets->exit, rel_cords);
	map->enemy = init_itbl_arr(assets->enemy, map->enemy_len, rel_cords);
}