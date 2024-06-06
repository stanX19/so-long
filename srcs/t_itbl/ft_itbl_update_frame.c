/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itbl_update_frame.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:28:26 by stan              #+#    #+#             */
/*   Updated: 2024/06/06 22:06:22 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_sprite_status	get_sprite_status(t_itbl_status status)
{
	if (status & DYING)
		return (DEATH);
	else if (status & ATTACKING)
		return (ATTACK);
	else if (status & MOVING)
		return (WALK);
	else
		return (IDLE);
}

static t_itbl_status	get_next_state(t_itbl_status status)
{
	if (status & DYING)
		return ((status | DEAD) & (~DYING));
	else if (status & ATTACKING)
		return (status & (~ATTACKING));
	else
		return (status);
}

static void	check_flip(t_itbl *itbl)
{
	if ((itbl->direction == RIGHT && !itbl->animation
			&& itbl->sprite_tab[LEFT][itbl->sp_status])
		|| (itbl->direction == LEFT && !itbl->animation
			&& itbl->sprite_tab[RIGHT][itbl->sp_status]))
	{
		itbl->animation = itbl->sprite_tab[LEFT][itbl->sp_status];
		itbl->_flip = 1;
	}
	else
		itbl->_flip = 0;
}

static void	set_animation(t_itbl *itbl)
{
	if (itbl->status == DEAD)
	{
		itbl->animation = 0;
		return ;
	}
	itbl->sp_status = get_sprite_status(itbl->status);
	itbl->animation = itbl->sprite_tab[itbl->direction][itbl->sp_status];
	check_flip(itbl);
}

void	ft_itbl_update_frame(t_itbl *itbl)
{
	set_animation(itbl);
	if (!itbl->animation)
	{
		itbl->sprite_idx = 0;
		ft_itbl_set_status(itbl, get_next_state(itbl->status));
		set_animation(itbl);
		return ;
	}
	++itbl->frame_tick;
	if (itbl->frame_tick >= itbl->animation->frame_interval)
	{
		itbl->frame_tick = 0;
		++itbl->sprite_idx;
	}
	if (itbl->sprite_idx >= itbl->animation->length)
	{
		itbl->sprite_idx = 0;
		ft_itbl_set_status(itbl, get_next_state(itbl->status));
		set_animation(itbl);
	}
}
