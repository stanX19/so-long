/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:36:37 by shatan            #+#    #+#             */
/*   Updated: 2024/06/17 17:42:26 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec2	vec2_sub(t_vec2 v1, t_vec2 v2)
{
	return ((t_vec2){v1.x - v2.x, v1.y - v2.y});
}
