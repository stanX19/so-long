/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_private.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:24:05 by shatan            #+#    #+#             */
/*   Updated: 2024/06/15 16:36:48 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_PRIVATE_H
# define DATA_PRIVATE_H
# include "so_long.h"

typedef struct s_map_init_data
{
	t_map				*map;
	struct				s_idx_data
	{
		int				enemy;
		int				coin;
	} idx;
	const t_itbl_dict	*dict;
	const t_itbl_dict	*hash;
}						t_map_init_data;

#endif  //DATA_PRIVATE
