#include "so_long.h"

t_map* ft_map_init(const char* path){
	t_map*	map;
	char**	raw_map;
	size_t	width;
	size_t	height;

	raw_map = ft_generate_raw_map(path, &width, &height);
	map = malloc(sizeof(t_map));
    map->grid = (t_tile **)ft_malloc_2d(width, height, sizeof(t_tile*), sizeof(t_tile));
	(void)raw_map;

	return map;
}