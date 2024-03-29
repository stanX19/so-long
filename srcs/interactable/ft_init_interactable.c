/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_interactable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:29:43 by stan              #+#    #+#             */
/*   Updated: 2024/02/14 17:29:57 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_stats	ft_init_stats(void)
{
	t_stats	stats;

	stats.speed = 5;
	stats.base_speed = stats.speed;
	stats.steps = 0;
	return (stats);
}

t_itbl	*ft_init_interactable(t_ani_sprite ***ani_sprite_tab)
{
	t_itbl	*ret;

	if (ani_sprite_tab == NULL)
		return (NULL);
	ret = ft_calloc(sizeof(t_itbl));
	if (ret == NULL)
		return (NULL);
	ret->direction = DOWN;
	ret->status = IDLING;
	ret->animation = ani_sprite_tab[DOWN][IDLE];
	ret->sprite_tab = ani_sprite_tab;
	ret->sp_status = IDLE;
	ret->stats = ft_init_stats();
	return (ret);
}
