/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_delete_vars.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:50:58 by stan              #+#    #+#             */
/*   Updated: 2024/06/15 20:13:51 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vars	*ft_init_vars(int argc, char **argv)
{
	t_vars	*vars;

	vars = (t_vars *)ft_calloc(sizeof(t_vars), 1);
	if (!vars)
	{
		ft_printf("Error\n\tInit vars: Failed to malloc\n");
	}
	vars->mlx = ft_mlx_init();
	if (!vars->mlx)
	{
		free(vars);
		return (0);
	}
	vars->assets = ft_init_assets(vars->mlx);
	vars->input = ft_init_input();
	vars->paths = argv + 1;
	vars->paths_len = argc - 1;
	vars->title = argv[0];
	return (vars);
}

void	ft_delete_vars(t_vars *vars)
{
	ft_input_destory(vars->input);
	ft_destory_assets(vars->assets);
	ft_mlx_destory(vars->mlx);
}
