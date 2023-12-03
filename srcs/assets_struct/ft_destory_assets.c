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

static void	_ani_sprite_destory(void* ptr)
{
	ft_ani_sprite_destory((t_ani_sprite *)ptr);
}

static void	_image_destory(void* ptr)
{
	ft_image_destory((t_image *)ptr);
}

void	ft_destory_assets(t_assets *assets)
{
	ft_free_list(&assets->all_ani_sprite, _ani_sprite_destory);
	ft_free_list(&assets->all_img, _image_destory);
	sprite_tab_destory(assets->enemy);
	sprite_tab_destory(assets->coin);
	sprite_tab_destory(assets->player);
	sprite_tab_destory(assets->exit);
	sprite_arr_destory(assets->all_tile, assets->all_tile_len);
	free(assets);
}