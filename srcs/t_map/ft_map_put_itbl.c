/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_put_itbl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:27:51 by shatan            #+#    #+#             */
/*   Updated: 2024/05/19 22:00:35 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_itbl_by_cord(t_image *img, t_vec2 tile_size, t_itbl *itbl,
		t_vec2	offset)
{
	t_vec2	display;

	if (itbl->status & DEAD)
		return ;
	display = ft_get_displayed_cord(tile_size, itbl);
	ft_put_interactable_to_img(img, itbl, display.x + offset.x, display.y
		+ offset.y);
}

static void	put_itbl_arr(t_image *img, t_vec2 tile_size, t_itbl_arr itbl_arr,
		t_vec2	offset)
{
	size_t	idx;

	idx = 0;
	while (idx < itbl_arr.len)
	{
		put_itbl_by_cord(img, tile_size, itbl_arr.arr[idx++], offset);
	}
}

void	ft_map_put_itbl(t_image *img, t_map *map, t_vec2 offset)
{
	t_vec2	tile_size;

	tile_size = map->assets->tile_size;
	put_itbl_arr(img, tile_size, map->coins, offset);
	put_itbl_by_cord(img, tile_size, map->exit, offset);
	put_itbl_arr(img, tile_size, map->enemies, offset);
	put_itbl_by_cord(img, tile_size, map->player, offset);
}
