/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_keyboard_event.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:40:49 by shatan            #+#    #+#             */
/*   Updated: 2024/06/17 12:49:37 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	match_key_to_input(int keycode)
{
	if (keycode == 65307 || keycode == 53)
		return ('\e');
	else if (keycode == 65289 || keycode == 48)
		return ('\t');
	else if (keycode == 49)
		return (' ');
	else if (keycode == 15)
		return ('r');
	else if (keycode == 13)
		return ('w');
	else if (keycode == 0)
		return ('a');
	else if (keycode == 1)
		return ('s');
	else if (keycode == 2)
		return ('d');
	else if (keycode < 128)
		return (keycode);
	else
		return (0);
}

// ft_printf("press %i\n", keycode);
int	ft_on_key_press(int keycode, t_vars *vars)
{
	vars->input->keyboard[match_key_to_input(keycode)] = 1;
	return (0);
}

// ft_printf("release %i\n", keycode);
int	ft_on_key_release(int keycode, t_vars *vars)
{
	vars->input->keyboard[match_key_to_input(keycode)] = 0;
	return (0);
}
