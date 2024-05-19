/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_update_all_status.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:27:43 by shatan            #+#    #+#             */
/*   Updated: 2024/05/20 01:45:31 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	just_died(t_map *map, t_itbl *itbl)
{
	if (itbl->status & (DYING | DEAD))
		return 0;
	if (itbl->faction & TILE_ENEMY)
	{
		if ((map->grid[itbl->cord.y][itbl->cord.x] & TILE_ALLY_ATK))
		{
			map->grid[itbl->cord.y][itbl->cord.x] &= ~TILE_ALLY_ATK;
			return (1);
		}
		return (0);
	}
	if (itbl->faction & TILE_PLAYER)
	{
		if (map->grid[itbl->cord.y][itbl->cord.x] & TILE_ENEMY)
			return (1);
	}
	if (!(map->grid[itbl->cord.y][itbl->cord.x] & itbl->self))
		return (1);
	return (0);
}

static void	m_update_itbl_status(t_map *map, t_itbl *itbl)
{
	if (just_died(map, itbl))
	{
		map->grid[itbl->cord.y][itbl->cord.x] &= ~(itbl->faction | itbl->self);
		ft_itbl_set_status(itbl, DYING);
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
