/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_dfs_target_tile.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:37:09 by shatan            #+#    #+#             */
/*   Updated: 2024/06/06 18:27:53 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vec2	ft_map_dfs_target_tile(t_map *map, t_vec2 cord, int depth,
		t_tile target)
{
	const t_vec2	d[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int				idx;
	t_vec2			ret_vec;
	t_vec2			vec;

	if (depth <= 0 || cord.x >= map->grid_size.x || cord.y >= map->grid_size.y
		|| cord.x < 0 || cord.y < 0)
		return ((t_vec2){1000, 1000});
	if (map->grid[cord.y][cord.x] & target)
		return ((t_vec2){0, 0});
	--depth;
	idx = 0;
	ret_vec = (t_vec2){1000, 1000};
	while (idx < 4)
	{
		vec = ft_map_dfs_target_tile(map, vec2_add(cord, d[idx]), depth,
				target);
		vec = vec2_add(vec, d[idx]);
		if (vec2_hypot(vec) <= depth)
			return (vec);
		if (vec2_hypot(vec) < vec2_hypot(ret_vec))
			ret_vec = vec;
		idx++;
	}
	return (ret_vec);
}
