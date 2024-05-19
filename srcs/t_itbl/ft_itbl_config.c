/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itbl_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:59:16 by stan              #+#    #+#             */
/*   Updated: 2024/05/19 21:15:24 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_itbl_config(t_itbl *itbl, t_itbl_cfg params)
{
	itbl->stats.base_speed = params.base_spd;
	itbl->offset = params.offset;
	itbl->self = params.self;
	itbl->blocking = params.blocking;
}
