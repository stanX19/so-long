/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:42:59 by shatan            #+#    #+#             */
/*   Updated: 2024/06/15 19:28:21 by stan             ###   ########.fr       */
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
}

void	ft_map_reset(t_map	*map)
{
	ft_itbl_destory(map->player);
	ft_itbl_destory(map->exit);
	free_itbl_arr(map->coins.arr, map->coins.len);
	free_itbl_arr(map->enemies.arr, map->enemies.len);
	ft_map_init_ibtl(map);
}
