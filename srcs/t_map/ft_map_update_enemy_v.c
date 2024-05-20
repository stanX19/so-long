/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_update_enemy_v.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:27:27 by shatan            #+#    #+#             */
/*   Updated: 2024/05/20 16:04:28 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_arr_v(t_itbl_arr itbl_arr)
{
	size_t	i;

	i = 0;
	while (i < itbl_arr.len)
	{
		itbl_arr.arr[i]->velocity.x += rand() % 10 / 9 - rand() % 10 / 9;
		itbl_arr.arr[i]->velocity.y += rand() % 10 / 9 - rand() % 10 / 9;
		itbl_arr.arr[i]->status |= MOVING;
		++i;
	}
}

void	ft_map_update_enemy_v(t_map *map)
{
	update_arr_v(map->enemies);
}
