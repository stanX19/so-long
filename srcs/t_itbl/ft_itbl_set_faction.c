/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itbl_set_faction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 22:51:13 by stan              #+#    #+#             */
/*   Updated: 2024/06/05 22:53:21 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_itbl_set_faction(t_itbl *itbl, t_tile faction)
{
	itbl->attack = 0;
	itbl->enemy = 0;
	itbl->faction = faction;
	if (faction & TILE_ENEMY)
	{
		itbl->attack |= TILE_ENEMY_ATK;
		itbl->enemy |= TILE_ALLY;
	}
	if (faction & TILE_ALLY)
	{
		itbl->attack |= TILE_ALLY_ATK;
		itbl->enemy |= TILE_ENEMY;
	}
}
