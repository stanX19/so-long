/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_ptr_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:39:15 by shatan            #+#    #+#             */
/*   Updated: 2024/02/02 14:42:31 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_ptr_arr(void **arr, size_t len, void (*free_func)(void *))
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free_func(arr[i++]);
	}
	free(arr);
}
