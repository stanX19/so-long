/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_itbl_just_died.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 23:26:28 by stan              #+#    #+#             */
/*   Updated: 2024/06/12 15:21:30 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_died_from_atk(t_map *map, t_itbl *itbl, t_tile faction,
		t_tile lethal_atk)
{
	if ((itbl->faction & faction)
		&& !(map->grid[itbl->cord.y][itbl->cord.x] & faction))
	{
		map->grid[itbl->cord.y][itbl->cord.x] |= faction;
		itbl->stats.hp -= 1;
	}
	(void)lethal_atk;
}

static bool	died_from_atk(t_map *map, t_itbl *itbl)
{
	const t_tile	all_atk = TILE_ALLY_ATK | TILE_WOLF_ATK
		| TILE_ENEMY_ATK | TILE_GOBLIN_ATK;

	check_died_from_atk(map, itbl, TILE_ENEMY, all_atk & (~TILE_ENEMY_ATK));
	check_died_from_atk(map, itbl, TILE_ALLY, all_atk & (~TILE_ALLY_ATK));
	check_died_from_atk(map, itbl, TILE_WOLF, all_atk & (~TILE_WOLF_ATK));
	check_died_from_atk(map, itbl, TILE_GOBLIN, all_atk & (~TILE_GOBLIN_ATK));
	if (itbl->stats.hp <= 0)
		return (1);
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
