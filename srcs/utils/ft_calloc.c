/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:39:00 by shatan            #+#    #+#             */
/*   Updated: 2024/02/02 14:43:17 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
		return (0);
	ft_memset(ret, 0, size);
	return (ret);
}
