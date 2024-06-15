/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:50:54 by stan              #+#    #+#             */
/*   Updated: 2024/06/15 20:17:40 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_state(t_vars *vars)
{
	if (vars->input->keyboard['\e'])
	{
		vars->state = STATE_QUIT;
	}
	else if ((vars->map->player->status & DEAD) || vars->input->keyboard['r'])
	{
		vars->state = STATE_RESET;
	}
	else if (vars->map->exit->status & DEAD)
	{
		vars->state = STATE_NEXT_GAME;
	}
}
static void	update_game(t_vars *vars)
{
	ft_update_player(vars);
	ft_map_update_enemy_v(vars->map);
	ft_map_update_itbl(vars->map);
	ft_show_steps(vars);
}

int	ft_main_loop(t_vars *vars)
{
	update_state(vars);
	ft_game_refresh(vars);
	if (vars->state == STATE_RUNNING)
		update_game(vars);
	else if (ft_has_input(vars->input))
		mlx_string_put(vars->mlx, vars->window->mlx_win, 10, 20, 0xFFFFFFFF,
			"GAME ENDED, RELEASE ALL KEYS");
	else if (vars->state == STATE_QUIT)
		ft_end_program(vars);
	else if (vars->state == STATE_RESET)
		ft_reset_game(vars);
	else if (vars->state == STATE_NEXT_GAME)
		ft_next_game(vars);
	return (0);
}
