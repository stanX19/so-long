/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_update_all_status.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:27:43 by shatan            #+#    #+#             */
/*   Updated: 2024/06/12 18:12:21 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	target_in_front(t_map *map, t_itbl *itbl)
{
	const t_vec2	displacement[] = {[LEFT] = {-1, 0}, [RIGHT] = {1, 0},
	[UP] = {0, 1}, [DOWN] = {0, -1}};
	int				dy;
	int				dx;

	if (!(map->grid[itbl->cord.y][itbl->cord.x] & itbl->enemy))
		return (false);
	dy = displacement[itbl->direction].y;
	dx = displacement[itbl->direction].x;
	if (dx == -ft_sign(itbl->rel_cord.x) || dy == -ft_sign(itbl->rel_cord.y))
		return (true);
	return (false);
}

static void	update_itbl_status(t_map *map, t_itbl *itbl)
{
	if (itbl->status & (DYING | DEAD))
		return ;
	if (ft_map_itbl_check_death(map, itbl))
	{
		map->grid[itbl->cord.y][itbl->cord.x] &= ~(itbl->faction | itbl->self);
		ft_itbl_set_status(itbl, DYING);
	}
	else if (itbl->can_atk && itbl != map->player
		&& target_in_front(map, itbl))
	{
		itbl->status |= ATTACKING;
		itbl->velocity = (t_vec2){0, 0};
	}
}

static void	update_arr(t_map *map, t_itbl_arr itbl_arr)
{
	size_t	idx;

	idx = -1;
	while (++idx < itbl_arr.len)
	{
		update_itbl_status(map, itbl_arr.arr[idx]);
	}
}

void	ft_map_update_all_status(t_map *map)
{
	update_itbl_status(map, map->player);
	update_itbl_status(map, map->exit);
	update_arr(map, map->coins);
	update_arr(map, map->enemies);
}
