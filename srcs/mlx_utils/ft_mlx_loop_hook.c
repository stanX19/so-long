/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_loop_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 19:39:16 by stan              #+#    #+#             */
/*   Updated: 2024/06/15 19:53:33 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mlx_loop_hook(t_vars *vars, int (*funct_ptr)())
{
	return (mlx_loop_hook(vars->mlx, funct_ptr, vars));
}
