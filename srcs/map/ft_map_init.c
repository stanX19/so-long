#include "so_long.h"

static void	init_memory(t_map * map, char ** raw_map, int width, int height)
{
	map = malloc(sizeof(t_map));
	map->grid = (t_tile **)ft_malloc_2d(width, height, sizeof(t_tile*), sizeof(t_tile));
	map->coins = (t_itbl **)malloc(sizeof(t_itbl *) * ft_2d_count_val(raw_map, width, height, 'C'));
	map->slimes = (t_itbl **)malloc(sizeof(t_itbl *) * ft_2d_count_val(raw_map, width, height, 'S'));
}

static void	init_value(t_map * map, char ** raw_map, int width, int height)
{
	map->grid_height = height;
	map->grid_width = width;
	// bkg_img later
	// call init_map_itbl
}

t_map* ft_map_init(const char* path){
	t_map*	map;
	char**	raw_map;
	size_t	width;
	size_t	height;

	raw_map = ft_generate_raw_map(path, &width, &height);
	map = init_memory(raw_map, width, height);
    
	(void)raw_map;

	return map;
}