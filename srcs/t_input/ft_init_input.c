/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:41:03 by shatan            #+#    #+#             */
/*   Updated: 2024/05/18 22:35:44 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_input	*ft_init_input(void)
{
	t_input	*ret;

	ret = (t_input *)ft_calloc(sizeof(t_input), 1);
	ret->esc_code = '\e';
	ret->tab_code = '\t';
	return (ret);
}
