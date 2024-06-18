/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:02:55 by stan              #+#    #+#             */
/*   Updated: 2024/05/04 12:25:09 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_tokens_len(const char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		i++;
	}
	return (i);
}
