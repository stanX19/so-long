#include "so_long.h"
#define STORE_SIZE 4

static t_itbl **init_itbl_arr(t_ani_sprite ***sprite_tab, int len)
{
	t_itbl **ret;
	int idx;

	if (len == 0)
		return 0;
	ret = (t_itbl **)malloc(sizeof(t_itbl*) * (len + 1));
	idx = 0;
	while (idx < len)
	{
		ret[idx++] = ft_init_interactable(sprite_tab);
	}
	ret[idx] = 0;
	return (ret);
}

void	ft_map_init_itbl(t_map *map, t_assets *assets)
{
	map->player1 = ft_init_interactable(assets->player);
	map->exit = ft_init_interactable(assets->exit);
	map->coins = init_itbl_arr(assets->coin, map->coin_len);
	map->enemy = init_itbl_arr(assets->enemy, map->enemy_len);
}