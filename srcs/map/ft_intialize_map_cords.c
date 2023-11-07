#include "so_long.h"


void assign_loc(t_map* map, char c, int x, int y, int slime_idx){
	switch (c)
	{
	case 'P':
		map->player1.loc = (t_vector2){x, y};
		return 0;
	case 'C':
		map->slimes[slime_idx].loc = (t_vector2){x, y};
	case 'E':
		map->exit.loc = (t_vector2){x, y};
		return 0;
	}	
}


void ft_initialize_map_cords(t_map* map, char** raw_map, size_t width, size_t height) {
	int slime_idx = 0;

    for (size_t x = 0; x < width; x++) {
        for (size_t y = 0; y < height; y++) {
            switch (raw_map[y][x]) {
                case '0':
                    map->grid[y][x] = PATH;
                    break;
                case '1':
                    map->grid[y][x] = WALL;
                    break;
                case '2':
                    map->grid[y][x] = WATER;
					break;
                default:
                    intialize_interactable(map, raw_map[y][x], (int)x, (int)y, slime_idx);
                    break;
            }
        }
    }
}
