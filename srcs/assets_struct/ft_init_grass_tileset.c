#include "so_long.h"
# define START (t_vec2){0, 0}
# define END SIZE
# define SIZE (t_vec2){16, 3}

static int get_idx(t_vec2 cord)
{
	return cord.y * END.x + cord.x;
}

static void set_grouped_tiles(t_assets *assets, t_sprite**src)
{
	int x;

	x = 0;
	while (x < END.x)
	{
		assets->tiles.path_wall[x] = src[get_idx((t_vec2){x, 0})];
		assets->tiles.water_path[x] = src[get_idx((t_vec2){x, 1})];
		assets->tiles.path_tree[x] = src[get_idx((t_vec2){x, 2})];
		++x;
	}
}

t_sprite** ft_init_connected_grass_tileset(t_assets *assets)
{
	t_image *	img;
	t_sprite **	ret;
	
	img = ft_read_xpm(assets, "./assets/sprites/tileset_grass_cntd_line.xpm");
	if (!img)
	{
		assets->tile_size.y = 0;
		assets->tile_size.x = 0;
		assets->all_tile_len = 0;
		set_grouped_tiles(assets, 0);
		return 0;
	}
	ret = ft_generate_sprites_array_grid(img, START, END, SIZE);
	if (!ret)
		return 0;
	assets->all_tile_len = SIZE.x * SIZE.y;
	assets->tile_size.y = ret[0]->height;
	assets->tile_size.x = ret[0]->width;
	set_grouped_tiles(assets, ret);
	return ret;
}

#undef START
#undef END
#undef SIZE