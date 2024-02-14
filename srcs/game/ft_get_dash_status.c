/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dash_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:51:06 by stan              #+#    #+#             */
/*   Updated: 2024/02/14 17:52:07 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_dash_status(t_input *input)
{
	static int	dash;

	if (dash % 2 == 0 && input->keyboard['\t'])
		dash++;
	else if (dash % 2 == 1 && !input->keyboard['\t'])
		dash++;
	if (dash == 4)
		dash = 0;
	return ((dash == 2) || input->mouse_right);
}
