/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:39:12 by shatan            #+#    #+#             */
/*   Updated: 2024/02/02 14:42:45 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_2d(void **ptr, size_t len)
{
	size_t	idx;

	idx = 0;
	while (idx < len)
	{
		if (ptr[idx])
			free(ptr[idx]);
		++idx;
	}
	free(ptr);
}
