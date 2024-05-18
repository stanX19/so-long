/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:20:38 by shatan            #+#    #+#             */
/*   Updated: 2024/05/18 22:34:28 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_ani_assets	init_ani_assets(t_assets *assets)
{
	t_ani_assets	ret;

	ret.coin = ft_init_coin_ani_sprites(assets);
	ret.bee = ft_init_bee_ani_sprites(assets);
	ret.slime = ft_init_slime_ani_sprites(assets);
	ret.slime2 = ft_init_slime2_ani_sprites(assets);
	ret.cat = ft_init_cat_ani_sprites(assets);
	ret.player = ft_init_player_ani_sprites(assets);
	return (ret);
}

static void	init_itbl(t_assets *assets)
{
	t_ani_assets	*ani_tabs;

	ani_tabs = &assets->ani_tabs;
	assets->coin = ft_init_interactable(ani_tabs->coin);
	assets->bee = ft_init_interactable(ani_tabs->bee);
	assets->slime = ft_init_interactable(ani_tabs->slime);
	assets->slime2 = ft_init_interactable(ani_tabs->slime2);
	assets->cat = ft_init_interactable(ani_tabs->cat);
	assets->player = ft_init_interactable(ani_tabs->player);
}

t_assets	*ft_init_assets(void *mlx)
{
	t_assets	*assets;

	assets = (t_assets *)ft_calloc(sizeof(t_assets), 1);
	if (!assets)
	{
		ft_printf("ERROR: Init assets: Failed to malloc\n");
		return (0);
	}
	assets->mlx = mlx;
	assets->ani_tabs = init_ani_assets(assets);
	init_itbl(assets);
	assets->all_tile = ft_init_line_fmt_tileset(assets,
			PATH_TILESET_BACKGROUND);
	return (assets);
}
