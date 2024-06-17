/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:50:54 by stan              #+#    #+#             */
/*   Updated: 2024/06/17 16:01:46 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_wait_loop(t_vars *vars)
{
	ft_game_display(vars);
	mlx_string_put(vars->mlx, vars->window->mlx_win, 10, 0, 0xFFFFFFFF,
		"GAME ENDED, RELEASE ALL KEYS");
	if (!ft_has_input(vars->input))
	{
		if (vars->state == STATE_QUIT)
			ft_end_program(vars);
		else if (vars->state == STATE_RESET)
			ft_reset_game(vars);
		else if (vars->state == STATE_NEXT_GAME)
			ft_next_game(vars);
		vars->state = STATE_RUNNING;
		ft_mlx_loop_hook(vars, ft_main_loop);
	}
	return (0);
}

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
	if (vars->state != STATE_RUNNING)
	{
		ft_mlx_loop_hook(vars, ft_wait_loop);
	}
}

int	ft_main_loop(t_vars *vars)
{
	ft_game_display(vars);
	ft_update_player(vars);
	ft_map_update_enemy_v(vars->map);
	ft_map_update_itbl(vars->map);
	ft_show_steps(vars);
	update_state(vars);
	return (0);
}
