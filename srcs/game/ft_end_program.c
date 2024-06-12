/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:16:06 by shatan            #+#    #+#             */
/*   Updated: 2024/06/12 14:16:06 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_end_program(t_vars *vars)
{
	ft_delete_game(vars);
	ft_delete_vars(vars);
	ft_printf("exited\n");
	exit(0);
}
