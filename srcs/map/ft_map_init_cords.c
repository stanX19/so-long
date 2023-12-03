#include "so_long.h"


typedef struct s_idx_data {
	int	slime;
	int bee;
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
	t_vec2 cord;

	cord = (t_vec2){d->x, d->y};
	switch (d->raw_map[d->y][d->x])
	{
	case 'P':
		d->map->player1->cord = cord;
		break;
	case 'E':
		d->map->exit->cord = cord;
		break;
	case 'C':
		d->map->coins.arr[(d->idx.coin)++]->cord = cord;
		break;
	case 'S':
		d->map->slimes.arr[(d->idx.slime)++]->cord = cord;
		break;
	case 'B':
		d->map->bees.arr[(d->idx.bee)++]->cord = cord;
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
		return TILE_PATH | TILE_SLIME;
	case 'B':
		return TILE_PATH | TILE_BEE;
	default:
		return TILE_PATH;
	}
}

void ft_map_init_cords(t_map* map, char** raw_map, int width, int height)
{
	t_loc_data	cord;

	cord = (t_loc_data){map, raw_map, 0, 0, {0, 0, 0}};
	while (cord.y < height)
	{
		cord.x = 0;
		while(cord.x < width)
		{
			map->grid[cord.y][cord.x] = get_grid_val(raw_map[cord.y][cord.x]);
			assign_sprites_loc(&cord);
			cord.x++;
		}
		cord.y++;
	}
}
