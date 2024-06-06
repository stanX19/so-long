/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destory_assets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:21:10 by shatan            #+#    #+#             */
/*   Updated: 2024/06/06 23:28:45 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	itbl_n_tab_destory(t_itbl *itbl)
{
	int	i;

	i = 0;
	while (i < NUM_DIRECTIONS)
	{
		free(itbl->sprite_tab[i++]);
	}
	free(itbl->sprite_tab);
	ft_itbl_destory(itbl);
}

static void	sprite_arr_destory(t_sprite **sp_arr, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		ft_sprite_destory(sp_arr[i++]);
	}
	free(sp_arr);
}

static void	_ani_sprite_destory(void *ptr)
{
	ft_ani_sprite_destory((t_ani_sprite *)ptr);
}

static void	_image_destory(void *ptr)
{
	ft_image_destory((t_image *)ptr);
}

void	ft_destory_assets(t_assets *assets)
{
	ft_free_list(&assets->all_ani_sprite, _ani_sprite_destory);
	ft_free_list(&assets->all_img, _image_destory);
	itbl_n_tab_destory(assets->slime);
	itbl_n_tab_destory(assets->slime2);
	itbl_n_tab_destory(assets->coin);
	itbl_n_tab_destory(assets->human);
	itbl_n_tab_destory(assets->cat);
	itbl_n_tab_destory(assets->bee);
	itbl_n_tab_destory(assets->wolf);
	itbl_n_tab_destory(assets->goblin);
	itbl_n_tab_destory(assets->portal);
	sprite_arr_destory(assets->all_tile, assets->all_tile_len);
	free(assets);
}
