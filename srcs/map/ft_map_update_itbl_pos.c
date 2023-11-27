#include "so_long.h"

static void	update_rel_cord(t_itbl *itbl)
{
	if (itbl->status != MOVING && itbl->status != ATTACKING)
	{
		return ;
	}
	switch (itbl->direction)
	{
	case LEFT:
		itbl->rel_cord.x -= itbl->stats.speed;
		break;
	case RIGHT:
        itbl->rel_cord.x += itbl->stats.speed;
        break;
    case UP:
        itbl->rel_cord.y -= itbl->stats.speed;
        break;
    case DOWN:
        itbl->rel_cord.y += itbl->stats.speed;
        break;
	}
}

static void check_rel_cord(t_map *map, t_itbl *itbl)
{
	t_vec2 new;

	new = (t_vec2){itbl->cord.x + sign(itbl->rel_cord.x), itbl->cord.y + sign(itbl->rel_cord.y)};
	if (new.x < 0 || new.x >= map->grid_size.x ||
		(map->grid[itbl->cord.y][new.x] & itbl->blocking))
	{
		itbl->rel_cord.x = 0; //sign(itbl->rel_cord.x) * (map->assets->tile_size.x * 3 / 4);
	}
	if (new.y < 0 || new.y >= map->grid_size.y ||
		(map->grid[new.y][itbl->cord.x] & itbl->blocking))
	{
		itbl->rel_cord.y = 0; //sign(itbl->rel_cord.y) * (map->assets->tile_size.y * 3 / 4);
	}
}

static void	update_pos(t_map *map, t_itbl *itbl)
{
	while (abs(itbl->rel_cord.x) > map->assets->tile_size.x)
	{
		itbl->cord.x += sign(itbl->rel_cord.x);
		++itbl->stats.steps;
		itbl->rel_cord.x = itbl->rel_cord.x -\
			sign(itbl->rel_cord.x) * 2 * map->assets->tile_size.x;
	}
	while (abs(itbl->rel_cord.y) > map->assets->tile_size.y)
	{
		itbl->cord.y += sign(itbl->rel_cord.y);
		++itbl->stats.steps;
		itbl->rel_cord.y = itbl->rel_cord.y -\
			sign(itbl->rel_cord.y) * 2 * map->assets->tile_size.y;
	}
}

static inline void update_check_update(t_map *map, t_itbl *itbl)
{
	check_rel_cord(map, itbl);
	update_rel_cord(itbl);
	update_pos(map, itbl);
}

void	ft_map_update_itbl_pos(t_map *map)
{
	size_t	idx;

	update_check_update(map, map->player1);
	update_check_update(map, map->exit);
	idx = 0;
	while (idx < map->coin_len)
	{
		update_check_update(map, map->coins[idx++]);
	}
	idx = 0;
	while (idx < map->enemy_len)
	{
		update_check_update(map, map->enemy[idx++]);
	}
}