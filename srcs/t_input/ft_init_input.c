/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:41:03 by shatan            #+#    #+#             */
/*   Updated: 2024/02/02 16:41:46 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_input	*ft_init_input(void)
{
	t_input	*ret;

	ret = ft_calloc(sizeof(t_input));
	ret->esc_code = '\e';
	ret->tab_code = '\t';
	return (ret);
}
