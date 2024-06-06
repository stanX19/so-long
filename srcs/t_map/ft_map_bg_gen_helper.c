/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_bg_gen_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:18:41 by shatan            #+#    #+#             */
/*   Updated: 2024/06/06 23:37:26 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_tile_size(int x)
{
	return (x * 2 - 1);
}

int	binary_4bit(int num4, int num3, int num2, int num1)
{
	return ((num4 << 3) | (num3 << 2) | (num2 << 1) | (num1));
}

void	map_equal_to(t_tile c[4], unsigned int val)
{
	c[0] = ((c[0] & val) == val);
	c[1] = ((c[1] & val) == val);
	c[2] = ((c[2] & val) == val);
	c[3] = ((c[3] & val) == val);
}

void	map_not_equal_to(t_tile c[4], unsigned int val)
{
	c[0] = (c[0] != val);
	c[1] = (c[1] != val);
	c[2] = (c[2] != val);
	c[3] = (c[3] != val);
}
