/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_destory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:50:44 by shatan            #+#    #+#             */
/*   Updated: 2024/06/12 13:05:03 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_window_destory(t_window *window)
{
	if (window == 0)
	{
		ft_printf("WARNING: mlx destory win: null pointer passed in");
		return ;
	}
	if (window->mlx == 0)
		printf("DEBUG: mlx is null\n");
	if (window->mlx_win == 0)
		printf("DEBUG: mlx win is null\n");
	printf("DEBUG: destoried\n");
	mlx_destroy_window(window->mlx, window->mlx_win);
	free(window);
}
