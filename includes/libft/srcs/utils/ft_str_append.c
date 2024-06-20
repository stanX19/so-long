/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:32:04 by stan              #+#    #+#             */
/*   Updated: 2024/06/20 10:02:59 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_append(char **ptr, const char *add)
{
	char	*new;

	new = ft_strjoin(*ptr, add);
	free(*ptr);
	*ptr = new;
}
