/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_itbl_front_add.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:28:53 by shatan            #+#    #+#             */
/*   Updated: 2024/02/02 15:41:18 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_vec2	get_target_cord(t_itbl *itbl)
{
	t_vec2	cord;

	cord = itbl->cord;
	if (itbl->direction == LEFT)
		return ((t_vec2){cord.x - 1, cord.y});
	else if (itbl->direction == RIGHT)
		return ((t_vec2){cord.x + 1, cord.y});
	else if (itbl->direction == UP)
		return ((t_vec2){cord.x, cord.y - 1});
	else if (itbl->direction == DOWN)
		return ((t_vec2){cord.x, cord.y + 1});
	else
		return (cord);
}

void	ft_map_itbl_front_add(t_map *map, t_itbl *itbl, t_tile val)
{
	t_vec2	target;

	target = get_target_cord(itbl);
	if (target.x < 0 || target.x >= map->grid_size.x)
		return ;
	if (target.y < 0 || target.y >= map->grid_size.x)
		return ;
	map->grid[target.y][target.x] |= val;
	ft_map_check_reaction(map, target);
}
