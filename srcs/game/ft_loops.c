/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:50:54 by stan              #+#    #+#             */
/*   Updated: 2024/06/13 00:56:02 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_wait_loop(t_vars *vars)
{
	ft_game_refresh(vars);
	mlx_string_put(vars->mlx, vars->window->mlx_win, 10, 20, 0xFFFFFFFF,
		"GAME ENDED, RELEASE ALL KEYS");
	if (!ft_has_input(vars->input))
	{
		ft_new_game(vars);
		mlx_loop_hook(vars->mlx, ft_update_loop, vars);
	}
	return (0);
}

int	ft_ending_loop(t_vars *vars)
{
	ft_game_refresh(vars);
	mlx_string_put(vars->mlx, vars->window->mlx_win, 10, 20, 0xFFFFFFFF,
		"GAME ENDED, RELEASE ALL KEYS");
	if (!ft_has_input(vars->input))
	{
		ft_end_program(vars);
	}
	return (1);
}

void	choose_loop(t_vars *vars)
{
	if (vars->input->keyboard['\e'])
	{
		mlx_loop_hook(vars->window->mlx, ft_ending_loop, vars);
	}
	else if (vars->map->exit->status & DEAD)
	{
		ft_print_steps(vars, "YOU WON!  |  Steps: %s\n");
		if (vars->idx + 1 >= vars->paths_len)
		{
			mlx_loop_hook(vars->mlx, ft_ending_loop, vars);
		}
		else
		{
			vars->idx++;
			mlx_loop_hook(vars->mlx, ft_wait_loop, vars);
		}
	}
	else if (vars->map->player->status & DEAD)
	{
		mlx_loop_hook(vars->mlx, ft_wait_loop, vars);
	}
}

int	ft_update_loop(t_vars *vars)
{
	ft_update_player(vars);
	ft_map_update_enemy_v(vars->map);
	ft_map_update_itbl(vars->map);
	ft_game_refresh(vars);
	ft_show_steps(vars);
	choose_loop(vars);
	return (0);
}
