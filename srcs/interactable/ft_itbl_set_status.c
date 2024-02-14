/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itbl_set_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:28:54 by stan              #+#    #+#             */
/*   Updated: 2024/02/14 17:28:54 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_itbl_set_status(t_itbl *itbl, t_itbl_status status)
{
	if (itbl->status != status)
	{
		itbl->sprite_idx = 0;
		itbl->frame_tick = 0;
	}
	itbl->status = status;
}
