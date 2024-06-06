/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_dfs_target_tile.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:37:09 by shatan            #+#    #+#             */
/*   Updated: 2024/06/06 23:14:42 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static inline bool	invalid_cord(t_map *map, t_vec2 cord, t_tile blocking)
{
	return (map->grid[cord.y][cord.x] & blocking
		|| cord.x >= map->grid_size.x || cord.y >= map->grid_size.y
		|| cord.x < 0 || cord.y < 0);
}

static t_vec2	get_best_vec(t_map *map, t_vec2 cord, int depth,
		t_tile target, t_tile blocking)
{
	const t_vec2	d[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int				idx;
	t_vec2			vec;
	t_vec2			best_vec;

	best_vec = (t_vec2){1000, 1000};
	idx = 0;
	while (idx < 4)
	{
		vec = ft_map_dfs_target_tile(map, vec2_add(cord, d[idx]), depth,
				target, blocking);
		vec = vec2_add(vec, d[idx]);
		if (vec2_hypot(vec) < vec2_hypot(best_vec))
			best_vec = vec;
		idx++;
	}
	return best_vec;
}

t_vec2	ft_map_dfs_target_tile(t_map *map, t_vec2 cord, int depth,
		t_tile target, t_tile blocking)
{
	t_vec2			best_vec;

	if (--depth < 0 || invalid_cord(map, cord, blocking | TILE_VISITED))
		return ((t_vec2){1000, 1000});
	if (map->grid[cord.y][cord.x] & target)
		return ((t_vec2){0, 0});
	map->grid[cord.y][cord.x] |= TILE_VISITED;
	best_vec = get_best_vec(map, cord, depth, target, blocking);
	map->grid[cord.y][cord.x] &= ~TILE_VISITED;
	return (best_vec);
}
