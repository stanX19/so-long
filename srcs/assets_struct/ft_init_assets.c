#include "so_long.h"

t_assets *	ft_init_assets(t_mlx_data *data)
{
	t_assets * assets;

	assets = (t_assets *)malloc(sizeof(t_assets));
	if (!assets)
	{
		ft_printf("ERROR: Init assets: Failed to malloc\n");
		return 0;
	}
	assets->mlx = data->mlx;
	assets->all_img.idx = 0;
	assets->all_ani_sprite.idx = 0;
	assets->coin = ft_init_coin_ani_sprites(assets);
	assets->enemy = ft_init_bee_ani_sprites(assets);
	assets->exit = ft_init_cat_ani_sprites(assets);
	assets->player = ft_init_player_ani_sprites(assets);
	assets->all_tile = ft_init_seperated_grass_tileset(assets);

	return assets;
}