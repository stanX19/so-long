/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:16:06 by shatan            #+#    #+#             */
/*   Updated: 2024/06/15 18:50:12 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_end_program(t_vars *vars)
{
	ft_delete_game(vars);
	ft_delete_vars(vars);
	ft_printf("exited\n");
	exit(0);
	return (1);
}
