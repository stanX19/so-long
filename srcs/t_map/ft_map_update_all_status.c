/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_update_all_status.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:27:43 by shatan            #+#    #+#             */
/*   Updated: 2024/06/03 22:04:23 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	just_died(t_map *map, t_itbl *itbl)
{
	if (itbl->faction & TILE_ENEMY)
	{
		if ((map->grid[itbl->cord.y][itbl->cord.x] & TILE_ALLY_ATK))
		{
			map->grid[itbl->cord.y][itbl->cord.x] &= ~TILE_ALLY_ATK;
			return (1);
		}
		return (0);
	}
	if ((itbl->faction & TILE_PLAYER)
		&& !(map->grid[itbl->cord.y][itbl->cord.x] & TILE_PLAYER))
		return (1);
	if ((itbl->faction & (TILE_COLLECTIBLE | TILE_EXIT))
		&& !(map->grid[itbl->cord.y][itbl->cord.x] & itbl->faction))
		return (1);
	return (0);
}

static bool	target_in_front(t_map *map, t_itbl *itbl)
{
	const t_vec2 displacement[] = {
		[LEFT] = { -1, 0 },
		[RIGHT] = { 1, 0 },
		[UP] = { 0, 1 },
		[DOWN] = { 0, -1 }
	};
	t_tile	enemy;
	int 	dy;
	int		dx;

	if (itbl->faction == TILE_ENEMY)
		enemy = TILE_PLAYER;
	else
		enemy = 0;
	dy = displacement[itbl->direction].y;
	dx = displacement[itbl->direction].x;

	return (map->grid[itbl->cord.y + dy][itbl->cord.x + dx] & enemy);
}

static void	m_update_itbl_status(t_map *map, t_itbl *itbl)
{
	if (itbl->status & (DYING | DEAD))
		return ;
	if (just_died(map, itbl))
	{
		map->grid[itbl->cord.y][itbl->cord.x] &= ~(itbl->faction | itbl->self);
		ft_itbl_set_status(itbl, DYING);
	}
	else if (itbl->can_atk && target_in_front(map, itbl))
	{
		itbl->status = ATTACKING;
		itbl->velocity = (t_vec2){0, 0};
	}
}

static void	m_update_arr(t_map *map, t_itbl_arr itbl_arr)
{
	size_t	idx;

	idx = -1;
	while (++idx < itbl_arr.len)
	{
		m_update_itbl_status(map, itbl_arr.arr[idx]);
	}
}

void	ft_map_update_all_status(t_map *map)
{
	m_update_itbl_status(map, map->player);
	m_update_itbl_status(map, map->exit);
	m_update_arr(map, map->coins);
	m_update_arr(map, map->enemies);
}
