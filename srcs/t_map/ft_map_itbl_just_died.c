/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_itbl_just_died.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 23:26:28 by stan              #+#    #+#             */
/*   Updated: 2024/06/06 00:00:36 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	died_from_atk(t_map *map, t_itbl *itbl)
{
	if ((itbl->faction & TILE_ENEMY)
		&& (map->grid[itbl->cord.y][itbl->cord.x] & TILE_ALLY_ATK))
	{
		map->grid[itbl->cord.y][itbl->cord.x] &= ~TILE_ALLY_ATK;
		return (1);
	}
	else if ((itbl->faction & TILE_ALLY)
		&& (map->grid[itbl->cord.y][itbl->cord.x] & TILE_ENEMY_ATK))
	{
		map->grid[itbl->cord.y][itbl->cord.x] &= ~TILE_ENEMY_ATK;
		return (1);
	}
	return (0);
}

bool	ft_map_itbl_check_death(t_map *map, t_itbl *itbl)
{
	if ((itbl->faction & TILE_PLAYER)
		&& !(map->grid[itbl->cord.y][itbl->cord.x] & TILE_PLAYER))
		return (1);
	if ((itbl->faction & (TILE_COLLECTIBLE | TILE_EXIT))
		&& !(map->grid[itbl->cord.y][itbl->cord.x] & itbl->faction))
		return (1);
	if (died_from_atk(map, itbl))
		return (1);
	return (0);
}
