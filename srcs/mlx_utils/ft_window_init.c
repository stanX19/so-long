/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:50:47 by shatan            #+#    #+#             */
/*   Updated: 2024/06/12 14:32:39 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window	*ft_window_init(void *mlx, int width, int height, char *title)
{
	t_window	*window;

	window = malloc(sizeof(t_window));
	if (!window)
	{
		ft_printf("Error\n\tWindow init: Failed to malloc");
		return (0);
	}
	window->mlx = mlx;
	window->mlx_win = mlx_new_window(mlx, width, height, title);
	window->title = title;
	window->width = width;
	window->height = height;
	return (window);
}
