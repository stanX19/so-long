/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:33:52 by shatan            #+#    #+#             */
/*   Updated: 2024/05/06 12:33:52 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc < 2)
	{
		ft_printf("Incorrect format. Please provide at least one path.\n");
		ft_printf("Usage: %s <path1> <path2> <path3> ...\n", argv[0]);
		return (1);
	}
	vars = ft_init_vars(argc, argv);
	if (!vars)
		return (1);
	ft_init_game(vars);
	ft_printf("running...\n");
	mlx_loop_hook(vars->mlx, ft_update_loop, vars);
	mlx_loop(vars->mlx);
	return (0);
}
