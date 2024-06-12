/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_destory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:49:04 by shatan            #+#    #+#             */
/*   Updated: 2024/06/12 12:59:49 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_destory(void *mlx)
{
	if (mlx == 0)
	{
		ft_printf("WARNING: mlx destory: null pointer passed in");
		return ;
	}
	free(mlx);
}
