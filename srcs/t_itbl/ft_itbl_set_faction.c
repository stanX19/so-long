/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itbl_set_faction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:51:13 by stan              #+#    #+#             */
/*   Updated: 2024/06/10 16:02:47 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_itbl_set_faction(t_itbl *itbl, t_tile faction)
{
	itbl->attack = 0;
	itbl->enemy = 0;
	itbl->faction = faction;
	itbl->blocking |= faction;
	if (faction & TILE_ENEMY)
	{
		itbl->attack |= TILE_ENEMY_ATK;
		itbl->enemy |= TILE_ALLY | TILE_WOLF | TILE_GOBLIN;
	}
	if (faction & TILE_ALLY)
	{
		itbl->attack |= TILE_ALLY_ATK;
		itbl->enemy |= TILE_ENEMY | TILE_WOLF | TILE_GOBLIN;
	}
	if (faction & TILE_WOLF)
	{
		itbl->attack |= TILE_WOLF_ATK;
		itbl->enemy |= TILE_GOBLIN | TILE_ALLY | TILE_ENEMY;
	}
	if (faction & TILE_GOBLIN)
	{
		itbl->attack |= TILE_GOBLIN_ATK;
		itbl->enemy |= TILE_WOLF | TILE_ALLY | TILE_ENEMY;
	}
}
