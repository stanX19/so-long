/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_private.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:24:05 by shatan            #+#    #+#             */
/*   Updated: 2024/06/10 15:24:05 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_PRIVATE_H
# define DATA_PRIVATE_H
# include "so_long.h"

typedef struct s_itbl_dict
{
	char		key;
	t_tile		faction;
	t_tile		background;
	t_itbl		*itbl;
}				t_itbl_dict;

typedef struct s_map_init_data
{
	t_map				*map;
	char				**raw_map;
	struct				s_idx_data
	{
		int				enemy;
		int				coin;
	} idx;
	t_itbl_dict			*dict;
	t_itbl_dict			*hash;
}						t_map_init_data;

#endif  //DATA_PRIVATE
