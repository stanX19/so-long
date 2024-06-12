/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_update_itbl_pos.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:26:30 by shatan            #+#    #+#             */
/*   Updated: 2024/06/13 01:32:56 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_rel_cord(t_itbl *itbl)
{
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

static void	map_move_itbl(t_map *map, t_itbl *itbl, int x_dis, int y_dis)
{
	int	val;

	val = map->grid[itbl->cord.y][itbl->cord.x] & (itbl->self | itbl->faction);
	map->grid[itbl->cord.y][itbl->cord.x] &= ~(itbl->self | itbl->faction);
	itbl->cord.x += x_dis;
	itbl->cord.y += y_dis;
	itbl->rel_cord.x -= x_dis * 2 * map->assets->tile_size.x;
	itbl->rel_cord.y -= y_dis * 2 * map->assets->tile_size.y;
	map->grid[itbl->cord.y][itbl->cord.x] |= val;
	ft_map_check_reaction(map, itbl->cord);
	++itbl->stats.steps;
}

static void	update_pos(t_map *map, t_itbl *itbl)
{
	ft_map_check_rel_cord(map, itbl);
	if (itbl->status & ATTACKING)
	{
		if (itbl->self & TILE_HUMAN)
		{
			ft_map_itbl_front_add(map, itbl, itbl->attack);
		}
		if (itbl->sprite_idx >= itbl->animation->length - 1)
			ft_map_itbl_pos_add(map, itbl, itbl->attack);
	}
	if (abs(itbl->rel_cord.x) > map->assets->tile_size.x)
	{
		map_move_itbl(map, itbl, ft_sign(itbl->rel_cord.x), 0);
		update_pos(map, itbl);
	}
	if (abs(itbl->rel_cord.y) > map->assets->tile_size.y)
	{
		map_move_itbl(map, itbl, 0, ft_sign(itbl->rel_cord.y));
		update_pos(map, itbl);
	}
}

static inline void	update_check_update(t_map *map, t_itbl *itbl)
{
	ft_map_check_velocity(map, itbl);
	if (!itbl->velocity.x && !itbl->velocity.y
		&& (itbl->status & (DEAD | IDLE)))
		return ;
	update_rel_cord(itbl);
	update_pos(map, itbl);
}

void	ft_map_update_itbl_pos(t_map *map)
{
	size_t	idx;

	idx = -1;
	while (++idx < map->coins.len)
	{
		if (!(map->coins.arr[idx]->status & (DYING | DEAD)))
			update_check_update(map, map->coins.arr[idx]);
	}
	idx = -1;
	while (++idx < map->enemies.len)
	{
		if (!(map->enemies.arr[idx]->status & (DYING | DEAD)))
			update_check_update(map, map->enemies.arr[idx]);
	}
	update_check_update(map, map->exit);
	update_check_update(map, map->player);
	ft_map_update_all_status(map);
}
