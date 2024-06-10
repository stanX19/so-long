/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check_reaction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:58:58 by shatan            #+#    #+#             */
/*   Updated: 2024/06/10 17:46:29 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	all_dead(t_map *map, t_itbl **arr, int len)
{
	int		idx;
	t_vec2	cord;

	idx = 0;
	while (idx < len)
	{
		cord = arr[idx]->cord;
		if (map->grid[cord.y][cord.x] & arr[idx]->faction)
		{
			return (0);
		}
		++idx;
	}
	return (1);
}

static void	remove_target_if_hit(t_tile *tile, t_tile target, t_tile attack)
{
	if ((*tile & target) && (*tile & attack))
		*tile &= ~target;
	*tile &= ~attack;
}

static void	check_atk_reaction(t_map *map, t_vec2 cord)
{
	t_tile			val;
	const t_tile	everyone = TILE_ENEMY | TILE_GOBLIN | TILE_WOLF | TILE_ALLY;

	val = map->grid[cord.y][cord.x];
	if ((val & (TILE_ENEMY_ATK | TILE_ENEMY | TILE_WOLF_ATK | TILE_GOBLIN_ATK))
		&& (val & TILE_PLAYER) && !(val & TILE_ALLY_ATK))
		val &= ~TILE_PLAYER;
	remove_target_if_hit(&val, everyone ^ TILE_ALLY, TILE_ALLY_ATK);
	remove_target_if_hit(&val, everyone ^ TILE_ENEMY, TILE_ENEMY_ATK);
	remove_target_if_hit(&val, everyone ^ TILE_WOLF, TILE_WOLF_ATK);
	remove_target_if_hit(&val, everyone ^ TILE_GOBLIN, TILE_GOBLIN_ATK);
	map->grid[cord.y][cord.x] = val;
}

void	ft_map_check_reaction(t_map *map, t_vec2 cord)
{
	t_tile	val;

	val = map->grid[cord.y][cord.x];
	if ((val & TILE_COLLECTIBLE) && (val & TILE_PLAYER))
		val &= ~TILE_COLLECTIBLE;
	if ((val & TILE_EXIT) && (val & TILE_PLAYER) && all_dead(map,
			map->coins.arr, map->coins.len))
		val &= ~TILE_EXIT;
	map->grid[cord.y][cord.x] = val;
	check_atk_reaction(map, cord);
}
