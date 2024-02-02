/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:49:10 by shatan            #+#    #+#             */
/*   Updated: 2024/02/02 17:49:10 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_window	*ft_mlx_init(void)
{
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
	{
		ft_printf("ERROR: Mlx init: Failed to mlx init\n");
	}
	return (mlx);
}
