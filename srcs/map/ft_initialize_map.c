#include "so_long.h"

t_tile** ft_malloc_2d(int width, int height){
    t_tile** map = (t_tile**)malloc(height * sizeof(int *));
    if (map == NULL) {
        return NULL;
    }

    for (int i = 0; i < height; i++) {
        map[i] = (t_tile *)malloc(width * sizeof(int));
        if (map[i] == NULL) {
			return NULL;
        }
    }

    return map;
}

t_map* ft_initialize_map(const char* path){
	t_map*	map;
	char**	raw_map;
	size_t	width;
	size_t	height;


	raw_map = ft_generate_raw_map(path, &width, &height);
	map = malloc(sizeof(t_map));
	map->grid = ft_malloc_2d(width, height);
	for (size_t x = 0; x < width; x++) {
		for (size_t y = 0; y < height; y++) {
			switch (raw_map[y][x])
			{
			case '0':
				map->grid[y][x] = PATH;
				break;
			case '1':
				map->grid[y][x] = WALL;
				break;
			case '2':
				map->grid[y][x] = WATER;
				break;
			case 'P': // player
				// initialize interactable sprite
				break;
			case 'C': // slime
				// count number
				break;
			case 'E': // exit
				// initialize interactable sprite
				break;
			default:
				map->grid[y][x] = PATH;
				break;
			}
		}
	}
	// initialize interactable sprite for slime
	return map;
}