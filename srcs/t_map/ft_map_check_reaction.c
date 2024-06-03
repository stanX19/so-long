/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check_reaction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:58:58 by shatan            #+#    #+#             */
/*   Updated: 2024/06/03 22:12:08 by stan             ###   ########.fr       */
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
		if (map->grid[cord.y][cord.x] & arr[idx]->self)
		{
			return (0);
		}
		++idx;
	}
	return (1);
}

void	ft_map_check_reaction(t_map *map, t_vec2 cord)
{
	t_tile	val;

	val = map->grid[cord.y][cord.x];
	if ((val & TILE_COLLECTIBLE) && (val & TILE_PLAYER))
		val &= ~TILE_COLLECTIBLE;
	if ((val & TILE_EXIT) && (val & TILE_PLAYER)
		&& all_dead(map, map->coins.arr, map->coins.len))
		val &= ~TILE_EXIT;
	if ((val & (TILE_ENEMY | TILE_ENEMY_ATK))
		&& (val & TILE_PLAYER) && !(val & TILE_ALLY_ATK))
		val &= ~TILE_PLAYER;
	if ((val & TILE_ALLY_ATK) && !(val & TILE_ENEMY))
		val &= ~TILE_ALLY_ATK;
	if ((val & TILE_ENEMY_ATK) && !(val & TILE_ENEMY))
		val &= ~TILE_ENEMY_ATK;
	map->grid[cord.y][cord.x] = val;
}
