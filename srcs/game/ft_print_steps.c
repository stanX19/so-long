/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_steps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:50:48 by stan              #+#    #+#             */
/*   Updated: 2024/02/14 17:50:49 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_show_steps(t_vars *vars)
{
	char	*step_count;

	step_count = ft_itoa(vars->map->player->stats.steps);
	mlx_string_put(vars->window->mlx, vars->window->mlx_win, 10, 20, 0xFFFFFFFF,
		step_count);
	free(step_count);
}

void	ft_print_steps(t_vars *vars, char *fmt_str)
{
	char	*step_count;

	step_count = ft_itoa(vars->map->player->stats.steps);
	ft_printf(fmt_str, step_count);
	free(step_count);
}
