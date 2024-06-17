/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_update_enemy_v.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:27:27 by shatan            #+#    #+#             */
/*   Updated: 2024/06/17 18:19:04 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define DEPTH 4

static void	random_movement(t_itbl *itbl)
{
	itbl->velocity.x += rand() % 10 / 9 - rand() % 10 / 9;
	itbl->velocity.y += rand() % 10 / 9 - rand() % 10 / 9;
	itbl->velocity.x %= itbl->stats.speed;
	itbl->velocity.y %= itbl->stats.speed;
	itbl->status |= MOVING;
}

static void	move_to_target(t_map *map, t_itbl *itbl, t_tile target)
{
	t_vec2	direction;
	t_tile	blocking;

	blocking = itbl->blocking & ~(itbl->self | itbl->faction);
	direction = ft_map_bfs_target_tile(
			(t_map_bfs_args){map, target, blocking, DEPTH}, itbl->cord);
	if (vec2_hypot(direction) < DEPTH)
	{
		itbl->velocity.x += direction.x;
		itbl->velocity.y += direction.y;
		itbl->velocity.x %= itbl->stats.speed;
		itbl->velocity.y %= itbl->stats.speed;
		itbl->status |= MOVING;
	}
	else
		random_movement(itbl);
}

void	ft_map_update_enemy_v(t_map *map)
{
	size_t	i;
	t_itbl	*itbl;

	i = 0;
	while (i < map->enemies.len)
	{
		itbl = map->enemies.arr[i];
		if (itbl->faction & (TILE_PLAYER))
			move_to_target(map, itbl, TILE_EXIT | TILE_COLLECTIBLE);
		else if (itbl->self & (TILE_WOLF))
			move_to_target(map, itbl, itbl->enemy);
		else
			random_movement(itbl);
		i++;
	}
}
