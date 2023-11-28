#include "so_long.h"


typedef struct s_idx_data {
	int	enemy;
	int	coin;
} t_idx_data;

typedef struct s_loc_data {
	t_map *			map;
	char **			raw_map;
	int				x;
	int				y;
	t_idx_data		idx;
} t_loc_data;

// static void assign_itbl_locs(t_map *map, t_itbl **itbl, t_tile val)
// {
// 	int idx;
// 	int x;
// 	int y;

// 	idx = 0;
// 	y = 0;
// 	x = 0;
// 	while (y < map->grid_size.y)
// 	{
// 		while (x < map->grid_size.x)
// 		{
// 			if (map->grid[y][x] & val)
// 				itbl[idx++]->loc = (t_vec2){x, y};
// 			++x;
// 		}
// 		++y;
// 	}
// }

void assign_sprites_loc(t_loc_data * d)
{
	switch (d->raw_map[d->y][d->x])
	{
	case 'P':
		d->map->player1->cord = (t_vec2){d->x, d->y};
		break;
	case 'E':
		d->map->exit->cord = (t_vec2){d->x, d->y};
		break;
	case 'C':
		d->map->coins[(d->idx.coin)++]->cord = (t_vec2){d->x, d->y};
		break;
	case 'S':
		d->map->enemy[(d->idx.enemy)++]->cord = (t_vec2){d->x, d->y};
		break;
	}
}

static t_tile get_grid_val(char c)
{
	switch (c)
	{
	case '1':
		return TILE_WALL;
	case '2':
		return TILE_WATER;
	case 'E':
		return TILE_PATH | TILE_EXIT;
	case 'C':
		return TILE_PATH | TILE_COIN;
	case 'P':
		return TILE_PATH | TILE_PLAYER1;
	case 'S':
		return TILE_PATH | TILE_ENEMY;
	default:
		return TILE_PATH;
	}
}

void ft_map_init_cords(t_map* map, char** raw_map, int width, int height)
{
	t_loc_data	loc_data;

	loc_data = (t_loc_data){map, raw_map, 0, 0, {0, 0}};
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			//ft_printf("%i %i\n", x, y);
			map->grid[y][x] = get_grid_val(raw_map[y][x]);
			loc_data.x = x;
			loc_data.y = y;
			assign_sprites_loc(&loc_data);
			//ft_printf("%i %i\n", loc_data.idx.coin, loc_data.idx.enemy);
		}
	}
}
