/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:52:13 by shatan            #+#    #+#             */
/*   Updated: 2024/06/22 12:20:03 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIGS_H
# define CONFIGS_H
# define BORDER_RATIO 0.333
# define DFS_DEPTH 3

typedef enum s_speed
{
	SPEED_DEFAULT = 2,
	SPEED_PLAYER = 4,
	SPEED_SLIME = 1,
	SPEED_BEE = 4,
	SPEED_WOLF = 4,
	SPEED_GOBLIN = 1,
}	t_speed;
#endif
