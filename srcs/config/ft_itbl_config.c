/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itbl_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:46:30 by stan              #+#    #+#             */
/*   Updated: 2024/06/17 18:42:46 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_config_default_itbl(t_assets *assets)
{
	ft_itbl_config(assets->coin, (t_itbl_cfg){SPEED_DEFAULT, TILE_COIN,
		(TILE_WALL | TILE_WATER), 1});
	ft_itbl_config(assets->human, (t_itbl_cfg){SPEED_PLAYER,
		TILE_HUMAN, (TILE_WALL | TILE_WATER), 1});
	ft_itbl_config(assets->cat, (t_itbl_cfg){SPEED_DEFAULT, TILE_CAT,
		(TILE_WALL | TILE_WATER), 1});
	ft_itbl_config(assets->slime, (t_itbl_cfg){SPEED_SLIME,
		TILE_SLIME, (TILE_WALL | TILE_WATER), 1});
	ft_itbl_config(assets->slime2, (t_itbl_cfg){SPEED_SLIME,
		TILE_SLIME, (TILE_WALL | TILE_WATER), 1});
	ft_itbl_config(assets->bee, (t_itbl_cfg){SPEED_BEE, TILE_BEE,
		(TILE_WALL), 1});
	ft_itbl_config(assets->wolf, (t_itbl_cfg){SPEED_WOLF, TILE_WOLF,
		(TILE_WALL | TILE_WATER), 1});
	ft_itbl_config(assets->goblin, (t_itbl_cfg){SPEED_GOBLIN,
		TILE_GOBLIN, (TILE_WALL | TILE_WATER), 1});
	ft_itbl_config(assets->portal, (t_itbl_cfg){SPEED_DEFAULT,
		TILE_PORTAL, (TILE_WALL | TILE_WATER), 1});
}
