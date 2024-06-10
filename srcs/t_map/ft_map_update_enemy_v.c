/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_update_enemy_v.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:27:27 by shatan            #+#    #+#             */
/*   Updated: 2024/06/10 15:11:28 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define DEPTH 3

static void	random_movement(t_itbl *itbl)
{
	itbl->velocity.x += rand() % 10 / 9 - rand() % 10 / 9;
	itbl->velocity.y += rand() % 10 / 9 - rand() % 10 / 9;
	itbl->velocity.x %= itbl->stats.speed;
	itbl->velocity.y %= itbl->stats.speed;
	itbl->status |= MOVING;
}

static void	move_to_enemy(t_map *map, t_itbl *itbl)
{
	t_vec2	direction;

	direction = ft_map_dfs_target_tile(map, itbl->cord, DEPTH, itbl->enemy,
			itbl->blocking ^ itbl->self);
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
		if (itbl->self & (TILE_WOLF))
			move_to_enemy(map, itbl);
		else
			random_movement(itbl);
		i++;
	}
}
