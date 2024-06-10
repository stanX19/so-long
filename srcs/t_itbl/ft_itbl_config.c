/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itbl_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:59:16 by stan              #+#    #+#             */
/*   Updated: 2024/06/10 14:52:32 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_itbl_config(t_itbl *itbl, t_itbl_cfg params)
{
	itbl->stats.base_speed = params.base_spd;
	itbl->offset = params.offset;
	itbl->self = params.self;
	itbl->blocking = params.blocking;
	itbl->stats.hp = params.hp;
}
