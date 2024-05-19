/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_update_itbl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:26:11 by shatan            #+#    #+#             */
/*   Updated: 2024/05/19 22:01:12 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_arr(t_itbl_arr itbl_arr)
{
	size_t	idx;

	idx = -1;
	while (++idx < itbl_arr.len)
	{
		ft_itbl_update_frame(itbl_arr.arr[idx]);
	}
}

static void	map_update_frames(t_map *map)
{
	ft_itbl_update_frame(map->player);
	ft_itbl_update_frame(map->exit);
	update_arr(map->enemies);
	update_arr(map->coins);
}

void	ft_map_update_itbl(t_map *map)
{
	ft_map_update_all_status(map);
	map_update_frames(map);
	ft_map_update_itbl_pos(map);
}
