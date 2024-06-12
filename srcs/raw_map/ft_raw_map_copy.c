/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raw_map_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:21:03 by shatan            #+#    #+#             */
/*   Updated: 2024/06/12 15:31:17 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_raw_map_copy(char *const *map, int width, int height)
{
	char	**ret;
	int		i;

	ret = (char **)ft_calloc_2d(height, width, sizeof(char *), sizeof(char));
	i = 0;
	while (i < height)
	{
		ft_memcpy(ret[i], map[i], width);
		i++;
	}
	return (ret);
}
