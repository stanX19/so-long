/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_raw_map_safe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:52:37 by shatan            #+#    #+#             */
/*   Updated: 2024/06/14 13:56:30 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_gen_raw_map_safe(const char *path, size_t *width, size_t *height)
{
	const char	*errstr;

	errstr = ft_is_invalid_map_file(path);
	if (errstr)
	{
		ft_dprintf(2, "Error\n\t%s: %s\n", path, errstr);
		return (NULL);
	}
	return (ft_generate_raw_map(path, width, height));
}
