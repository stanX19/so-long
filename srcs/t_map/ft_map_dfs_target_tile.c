/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_dfs_target_tile.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:37:09 by shatan            #+#    #+#             */
/*   Updated: 2024/06/13 22:15:47 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static inline bool	invalid_cord(t_map *map, t_vec2 cord, t_tile blocking)
{
	return (map->grid[cord.y][cord.x] & blocking || cord.x >= map->grid_size.x
		|| cord.y >= map->grid_size.y || cord.x < 0 || cord.y < 0);
}

static t_vec2	get_best_vec(t_map_dfs_args args, t_vec2 cord, int depth)
{
	const t_vec2	d[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int				idx;
	t_vec2			vec;
	t_vec2			best_vec;

	best_vec = (t_vec2){1000, 1000};
	idx = 0;
	while (idx < 4)
	{
		vec = ft_map_dfs_target_tile(args, vec2_add(cord, d[idx]), depth);
		vec = vec2_add(vec, d[idx]);
		if (vec2_hypot(vec) < vec2_hypot(best_vec))
			best_vec = vec;
		idx++;
	}
	return (best_vec);
}

t_vec2	ft_map_dfs_target_tile(t_map_dfs_args args, t_vec2 cord, int depth)
{
	t_vec2	best_vec;

	if (--depth < 0 || invalid_cord(args.map, cord,
			args.blocking | TILE_VISITED))
		return ((t_vec2){1000, 1000});
	if (args.map->grid[cord.y][cord.x] & args.target)
		return ((t_vec2){0, 0});
	args.map->grid[cord.y][cord.x] |= TILE_VISITED;
	best_vec = get_best_vec(args, cord, depth);
	args.map->grid[cord.y][cord.x] &= ~TILE_VISITED;
	return (best_vec);
}
