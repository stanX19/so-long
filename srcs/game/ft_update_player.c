/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:50:30 by stan              #+#    #+#             */
/*   Updated: 2024/06/13 00:28:26 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_atk(t_itbl *player, t_input *input)
{
	if (input->mouse_left || input->keyboard[' '])
	{
		if (!(player->status & ATTACKING))
		{
			player->frame_tick = 0;
			player->sprite_idx = 0;
		}
		player->status |= ATTACKING;
	}
}

static void	update_vel(t_itbl *player, t_input *input)
{
	player->stats.speed = player->stats.base_speed * (1
			+ ft_get_dash_status(input) * 1000);
	player->velocity.x = player->stats.speed * (input->keyboard['d']
			- input->keyboard['a']);
	player->velocity.y = player->stats.speed * (input->keyboard['s']
			- input->keyboard['w']);
	player->status &= ~MOVING;
	player->status |= MOVING * (player->velocity.x || player->velocity.y);
}

void	ft_update_player(t_vars *vars)
{
	update_vel(vars->map->player, vars->input);
	update_atk(vars->map->player, vars->input);
	ft_itbl_update_direction(vars->map->player);
}
