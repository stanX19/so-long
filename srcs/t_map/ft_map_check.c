/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:02:31 by shatan            #+#    #+#             */
/*   Updated: 2024/05/20 00:54:29 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static inline t_vec2	get_border(t_vec2 tile_size)
{
	return ((t_vec2){BORDER_RATIO * tile_size.x,
		BORDER_RATIO * tile_size.y});
}

static inline t_vec2	get_new_by_sign(t_vec2 old, t_vec2 dis)
{
	return ((t_vec2){old.x + ft_sign(dis.x), old.y + ft_sign(dis.y)});
}

static inline t_vec2	is_blocking(t_map *map, t_vec2 old, t_vec2 new,
		t_tile blocking)
{
	t_vec2	ret;

	ret = (t_vec2){0, 0};
	if (new.x < 0 || new.x >= map->grid_size.x
		|| map->grid[old.y][new.x] & blocking)
	{
		ret.x = 1;
	}
	if (new.y < 0 || new.y >= map->grid_size.y
		|| map->grid[new.y][old.x] & blocking)
	{
		ret.y = 1;
	}
	return (ret);
}

void	ft_map_check_velocity(t_map *map, t_itbl *itbl)
{
	t_vec2	new;
	t_vec2	border;
	t_vec2	blocking;

	border = get_border(map->assets->tile_size);
	new = get_new_by_sign(itbl->cord, vec2_add(itbl->rel_cord,
				itbl->velocity));
	blocking = is_blocking(map, itbl->cord, new, itbl->blocking);
	if (blocking.x)
	{
		if (itbl->rel_cord.x + itbl->velocity.x > border.x)
			itbl->velocity.x = border.x - itbl->rel_cord.x;
		else if (itbl->rel_cord.x + itbl->velocity.x < -border.x)
			itbl->velocity.x = -border.x - itbl->rel_cord.x;
	}
	if (blocking.y)
	{
		if (itbl->rel_cord.y + itbl->velocity.y > border.y)
			itbl->velocity.y = border.y - itbl->rel_cord.y;
		else if (itbl->rel_cord.y + itbl->velocity.y < -border.y)
			itbl->velocity.y = -border.y - itbl->rel_cord.y;
	}
	itbl->velocity.x %= itbl->stats.speed + 1;
	itbl->velocity.y %= itbl->stats.speed + 1;
}

void	ft_map_check_rel_cord(t_map *map, t_itbl *itbl)
{
	t_vec2	new;
	t_vec2	border;
	t_vec2	blocking;

	border = get_border(map->assets->tile_size);
	new = get_new_by_sign(itbl->cord, itbl->rel_cord);
	blocking = is_blocking(map, itbl->cord, new, itbl->blocking);
	if (blocking.x)
	{
		if (abs(itbl->rel_cord.x) > border.x)
			itbl->rel_cord.x = ft_sign(itbl->rel_cord.x) * border.x;
	}
	if (blocking.y)
	{
		if (abs(itbl->rel_cord.y) > border.y)
			itbl->rel_cord.y = ft_sign(itbl->rel_cord.y) * border.y;
	}
}
