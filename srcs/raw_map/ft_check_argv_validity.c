/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv_validity.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:51:44 by stan              #+#    #+#             */
/*   Updated: 2024/06/12 15:43:33 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// true : ko
// false: ok
bool	ft_check_argv_validity(char *const *argv, int argc)
{
	int			i;
	int			ko;
	const char	*errstr;

	ko = false;
	i = 1;
	while (i < argc)
	{
		errstr = ft_is_invalid_map_file(argv[i]);
		if (errstr)
		{
			if (!ko)
				ft_dprintf(2, "Error\n");
			ko = true;
			ft_dprintf(2, "\t%-20s: %s\n", argv[i], errstr);
		}
		i++;
	}
	return (ko);
}
