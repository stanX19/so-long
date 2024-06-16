/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 23:50:19 by stan              #+#    #+#             */
/*   Updated: 2024/06/16 23:50:22 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_next_game(t_vars *vars)
{
	ft_print_steps(vars, "YOU WON!  |  Steps: %s\n");
	if (vars->idx + 1 >= vars->paths_len)
		ft_end_program(vars);
	vars->idx++;
	ft_new_game(vars);
}
