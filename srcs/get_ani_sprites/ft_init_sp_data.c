/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sp_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:30:51 by stan              #+#    #+#             */
/*   Updated: 2024/02/14 17:30:59 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sp_data(t_sp_data sp_data[NUM_DIRECTIONS][NUM_ACTIONS])
{
	int	i;
	int	j;

	i = 0;
	while (i < NUM_DIRECTIONS)
	{
		j = 0;
		while (j < NUM_ACTIONS)
		{
			sp_data[i][j++] = (t_sp_data){0, {0, 0}, {0, 0}, {0, 0}};
		}
		i++;
	}
}
