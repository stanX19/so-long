#include "so_long.h"

t_sprite** ft_init_grass_tileset(t_assets *assets)
{
	t_image *	img;
	t_sprite **	ret;
	
	img = ft_read_xpm(assets, "assets/sprites/tileset_grass.xpm");\
	if (!img)
		return 0;
	ret = ft_generate_sprites_array_grid(img, (t_vec2){0, 0}, (t_vec2){12 ,9}, (t_vec2){12 ,21});
	if (!ret)
		return 0;
	assets->all_tile_len = 12 * 9;
	assets->tile_size.y = ret[0]->height;
	assets->tile_size.x = ret[0]->width;
	return ret;
}