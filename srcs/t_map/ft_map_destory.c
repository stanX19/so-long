/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_destory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:58:40 by shatan            #+#    #+#             */
/*   Updated: 2024/06/15 16:46:20 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_itbl_arr(t_itbl **arr, size_t len)
{
	size_t	idx;

	if (arr == NULL)
		return ;
	idx = 0;
	while (idx < len)
	{
		ft_itbl_destory(arr[idx++]);
	}
	free(arr);
}

void	ft_map_destory(t_map *map)
{
	ft_free_2d((void **)map->grid, map->grid_size.y);
	ft_free_2d((void **)map->raw.grid, map->raw.height);
	ft_itbl_destory(map->player);
	ft_itbl_destory(map->exit);
	free_itbl_arr(map->coins.arr, map->coins.len);
	free_itbl_arr(map->enemies.arr, map->enemies.len);
	free(map);
}
