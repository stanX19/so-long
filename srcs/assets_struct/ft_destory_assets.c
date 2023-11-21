#include "so_long.h"

static void	sprite_tab_destory(t_ani_sprite ***	sprite_tab)
{
	int i;

	i = 0;
	while (i < NUM_DIRECTIONS)
	{
		free(sprite_tab[i++]);
	}
	free(sprite_tab);
}

static void	sprite_arr_destory(t_sprite **sp_arr, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		ft_sprite_destory(sp_arr[i++]);
	}
	free(sp_arr);
}

static void	free_free_arr(t_assets *assets)
{
	int i;

	i = 0;
	while (i < assets->all_img.idx)
	{
		ft_image_destory(assets, assets->all_img.arr[i++]);
	}
	i = 0;
	while (i < assets->all_ani_sprite.idx)
	{
		ft_ani_sprite_destory(assets->all_ani_sprite.arr[i++]);
	}
}

void	ft_destory_assets(t_assets *assets)
{
	free_free_arr(assets);
	sprite_tab_destory(assets->enemy);
	sprite_tab_destory(assets->coin);
	sprite_tab_destory(assets->player);
	sprite_tab_destory(assets->exit);
	sprite_arr_destory(assets->all_tile, assets->all_tile_len);
	free(assets);
}