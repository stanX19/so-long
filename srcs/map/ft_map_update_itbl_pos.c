#include "so_long.h"
#define BORDER_RATIO 1 / 2

static void	update_rel_cord(t_itbl *itbl)
{
	if (itbl->velocity.x || itbl->velocity.y)
		itbl->status |= MOVING;
	else
		itbl->status &= ~MOVING;
	if (itbl->velocity.x > 0)
		itbl->direction = RIGHT;
	else if (itbl->velocity.x < 0)
		itbl->direction = LEFT;
	else if (itbl->velocity.y > 0)
		itbl->direction = DOWN;
	else if (itbl->velocity.y < 0)
		itbl->direction = UP;
	itbl->rel_cord.x += itbl->velocity.x;
	itbl->rel_cord.y += itbl->velocity.y;
}

static void check_rel_cord(t_map *map, t_itbl *itbl)
{
	t_vec2 new;
	t_vec2 border;

	border = (t_vec2){map->assets->tile_size.x * BORDER_RATIO,
		map->assets->tile_size.y * BORDER_RATIO};
	new = (t_vec2){itbl->cord.x + sign(itbl->rel_cord.x),
		itbl->cord.y + sign(itbl->rel_cord.y)};
	if (new.x < 0 || new.x >= map->grid_size.x ||
		(map->grid[itbl->cord.y][new.x] & itbl->blocking))
	{
		if (abs(itbl->rel_cord.x) > border.x)
			itbl->rel_cord.x = sign(itbl->rel_cord.x) * border.x;
	}
	if (new.y < 0 || new.y >= map->grid_size.y ||
		(map->grid[new.y][itbl->cord.x] & itbl->blocking))
	{
		if (abs(itbl->rel_cord.y) > border.y)
			itbl->rel_cord.y = sign(itbl->rel_cord.y) * border.y;
	}
}

static void	map_move_itbl(t_map *map, t_itbl *itbl, int x_dis, int y_dis)
{
	map->grid[itbl->cord.y][itbl->cord.x] &= ~itbl->self;
	itbl->cord.x += x_dis;
	itbl->cord.y += y_dis;
	itbl->rel_cord.x -=	x_dis * 2 * map->assets->tile_size.x;
	itbl->rel_cord.y -=	y_dis * 2 * map->assets->tile_size.y;
	map->grid[itbl->cord.y][itbl->cord.x] |= itbl->self;
	++itbl->stats.steps;
}

static void	update_pos(t_map *map, t_itbl *itbl)
{
	while (abs(itbl->rel_cord.x) > map->assets->tile_size.x)
	{
		map_move_itbl(map, itbl, sign(itbl->rel_cord.x), 0);
		ft_map_check_reaction(map, itbl->cord);
		check_rel_cord(map, itbl);
	}
	while (abs(itbl->rel_cord.y) > map->assets->tile_size.y)
	{
		map_move_itbl(map, itbl, 0, sign(itbl->rel_cord.y));
		ft_map_check_reaction(map, itbl->cord);
		check_rel_cord(map, itbl);
	}
}

static inline void update_check_update(t_map *map, t_itbl *itbl)
{
	update_rel_cord(itbl);
	check_rel_cord(map, itbl);
	update_pos(map, itbl);
	ft_map_update_all_status(map);
}

void	ft_map_update_itbl_pos(t_map *map)
{
	size_t	idx;

	update_check_update(map, map->player1);
	update_check_update(map, map->exit);
	idx = 0;
	while (idx < map->coin_len)
	{
		if (!(map->coins[idx]->status & (DYING | DEAD)))
			update_check_update(map, map->coins[idx]);
		++idx;
	}
	idx = 0;
	while (idx < map->enemy_len)
	{
		if (!(map->enemy[idx]->status & (DYING | DEAD)))
			update_check_update(map, map->enemy[idx]);
		++idx;
	}
}