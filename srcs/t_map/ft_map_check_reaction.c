/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check_reaction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:58:58 by shatan            #+#    #+#             */
/*   Updated: 2024/05/20 01:06:01 by stan             ###   ########.fr       */
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
	if ((val & TILE_COIN) && (val & TILE_PLAYER))
		val &= ~TILE_COIN;
	if ((val & TILE_EXIT) && (val & TILE_PLAYER)
		&& all_dead(map, map->coins.arr, map->coins.len))
		val &= ~TILE_EXIT;
	if ((val & TILE_ENEMY) && (val & TILE_PLAYER) && !(val & TILE_ALLY_ATK))
		val &= ~TILE_PLAYER;
	if ((val & TILE_ALLY_ATK) && !(val & TILE_ENEMY))
		val &= ~TILE_ALLY_ATK;
	map->grid[cord.y][cord.x] = val;
}
