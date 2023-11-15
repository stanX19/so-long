#include "so_long.h"


typedef struct s_idx_data {
	int	slime;
	int	coin;
} t_idx_data;

typedef struct s_loc_data {
	t_map *			map;
	char **			raw_map;
	int				x;
	int				y;
	t_idx_data		idx;
} t_loc_data;

void assign_sprites_loc(t_loc_data * d)
{
	switch (d->raw_map[d->y][d->x])
	{
	case 'P':
		d->map->player1->loc = (t_vec2){d->x, d->y};
		break;
	case 'C':
		d->map->coins[(d->idx.coin)++]->loc = (t_vec2){d->x, d->y};
		break;
	case 'S':
		d->map->slimes[(d->idx.slime)++]->loc = (t_vec2){d->x, d->y};
		break;
	case 'E':
		d->map->exit->loc = (t_vec2){d->x, d->y};
		break;
	}	
}

void assign_grid_loc(t_loc_data * d)
{
	switch (d->raw_map[d->y][d->x])
	{
	case '0':
		d->map->grid[d->y][d->x] = PATH;
		break;
	case '1':
		d->map->grid[d->y][d->x] = WALL;
		break;
	case '2':
		d->map->grid[d->y][d->x] = WATER;
		break;
	default:
		assign_sprites_loc(d);
	}
}

void ft_map_init_cords(t_map* map, char** raw_map, int width, int height)
{
	t_loc_data	loc_data;

	loc_data = (t_loc_data){map, raw_map, 0, 0, {0, 0}};
	for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
			loc_data.x = x;
			loc_data.y = y;
			assign_grid_loc(&loc_data);
		}
	}
}
