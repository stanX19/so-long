/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_itbl_pos_add.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:28:53 by shatan            #+#    #+#             */
/*   Updated: 2024/06/04 13:53:20 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_itbl_pos_add(t_map *map, t_itbl *itbl, t_tile val)
{
	t_vec2	target;

	target = itbl->cord;
	map->grid[target.y][target.x] |= val;
	ft_map_check_reaction(map, target);
}
