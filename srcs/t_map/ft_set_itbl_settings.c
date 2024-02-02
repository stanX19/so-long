/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_itbl_settings.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:20:14 by shatan            #+#    #+#             */
/*   Updated: 2024/02/02 15:25:19 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_itbl(t_itbl *itbl, const t_itbl_cfg params)
{
	itbl->stats.base_speed = params.base_spd;
	itbl->offset = params.offset;
	itbl->self = params.self;
	itbl->blocking = params.blocking;
}

void	ft_set_itbl_settings(t_itbl *itbl, t_tile self)
{
	t_itbl_cfg	params[ITBL_CFG_PARAMS_SIZE];
	int			idx;

	params[0] = (t_itbl_cfg){0, {0, 0}, TILE_COIN, (TILE_WALL | TILE_WATER)};
	params[1] = (t_itbl_cfg){SPEED_PLAYER, {-24, -32}, TILE_PLAYER,
		(TILE_WALL | TILE_WATER)};
	params[2] = (t_itbl_cfg){0, {-4, -8}, TILE_EXIT, (TILE_WALL | TILE_WATER)};
	params[3] = (t_itbl_cfg){SPEED_SLIME, {-16, -16}, TILE_SLIME,
		(TILE_WALL | TILE_WATER | TILE_SLIME)};
	params[4] = (t_itbl_cfg){SPEED_SLIME, {-16, -16}, TILE_BEE,
		(TILE_WALL | TILE_BEE)};
	idx = 0;
	while (idx < ITBL_CFG_PARAMS_SIZE)
	{
		if (params[idx].self == self)
		{
			set_itbl(itbl, params[idx]);
			return ;
		}
		idx++;
	}
	set_itbl(itbl, (t_itbl_cfg){0, {0, 0}, 0, 0});
}
#undef ITBL_CFG_PARAMS_SIZE