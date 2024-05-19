/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itbl_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:29:18 by stan              #+#    #+#             */
/*   Updated: 2024/05/18 22:33:45 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_itbl	*ft_itbl_copy(t_itbl *src)
{
	t_itbl	*ret;

	if (src == 0)
		return (0);
	ret = (t_itbl *)ft_calloc(sizeof(t_itbl), 1);
	if (ret == 0)
		return (0);
	ft_memcpy(ret, src, sizeof(t_itbl));
	return (ret);
}
