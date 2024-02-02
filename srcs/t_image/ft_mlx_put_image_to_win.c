/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_put_image_to_win.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:56:59 by shatan            #+#    #+#             */
/*   Updated: 2024/02/02 16:57:14 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mlx_put_image_to_win(t_window *window, t_image *img, int x, int y)
{
	return (mlx_put_image_to_window(window->mlx, window->mlx_win,
			img->img, x, y));
}
