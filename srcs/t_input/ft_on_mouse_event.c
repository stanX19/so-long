/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_mouse_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:22:59 by shatan            #+#    #+#             */
/*   Updated: 2024/02/02 16:23:38 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// ft_printf("click button %i; (%i, %i)\n", button, x, y);
int	ft_on_mouse_click(int button, int x, int y, t_vars *vars)
{
	if (button == 1)
		vars->input->mouse_left = 1;
	else if (button == 2 || button == 3)
		vars->input->mouse_right = 1;
	(void)x;
	(void)y;
	return (0);
}

// ft_printf("release button %i; (%i, %i)\n", button, x, y);
int	ft_on_mouse_release(int button, int x, int y, t_vars *vars)
{
	if (button == 1)
		vars->input->mouse_left = 0;
	else if (button == 2 || button == 3)
		vars->input->mouse_right = 0;
	(void)x;
	(void)y;
	return (0);
}
