#include "so_long.h"

static t_map * init_base(char ** raw_map, int width, int height)
{
	t_map * map;

	map = (t_map *)ft_calloc(sizeof(t_map));
	map->grid = (t_tile **)ft_calloc_2d(height, width, sizeof(t_tile*), sizeof(t_tile));
	map->coin_len = ft_2d_count_val(raw_map, width, height, 'C');
	map->enemy_len = ft_2d_count_val(raw_map, width, height, 'S');
	map->grid_size.x = width;
	map->grid_size.y = height;

	return map;
}

t_map* ft_map_init(const char* path, t_assets * assets)
{
	t_map*	map;
	char**	raw_map;
	size_t	width;
	size_t	height;

	raw_map = ft_generate_raw_map(path, &width, &height);
	map = init_base(raw_map, width, height);
	ft_map_init_itbl(map, assets);
	ft_map_init_cords(map, raw_map, width, height);
	ft_free_2d((void **)raw_map, height);
	map->bkg_img = ft_map_bg_gen(map, assets);
	map->assets = assets;
	return map;
}