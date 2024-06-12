/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_listeners.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:22:10 by shatan            #+#    #+#             */
/*   Updated: 2024/06/12 13:26:51 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook_listeners(t_vars *vars)
{
	mlx_do_key_autorepeatoff(vars->window->mlx);
	mlx_hook(vars->window->mlx_win, ON_KEYDOWN, KEY_PRESS_MASK,
		ft_on_key_press, vars);
	mlx_hook(vars->window->mlx_win, ON_KEYUP, KEY_RELEASE_MASK,
		ft_on_key_release, vars);
	mlx_hook(vars->window->mlx_win, ON_MOUSEDOWN, BUTTON_PRESS_MASK,
		ft_on_mouse_click, vars);
	mlx_hook(vars->window->mlx_win, ON_MOUSEUP, BUTTON_RELEASE_MASK,
		ft_on_mouse_release, vars);
	mlx_hook(vars->window->mlx_win, ON_DESTROY, NO_EVENT_MASK,
		ft_on_destory, vars);
}
