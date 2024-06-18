/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_itbl_dict.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:43:56 by stan              #+#    #+#             */
/*   Updated: 2024/06/18 15:50:38 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// PCE are constants that cannot be changed
// char, faction, on_path, animation
const t_itbl_dict	*ft_get_itbl_dict(t_assets *assets)
{
	static t_itbl_dict	ret[100];
	const t_itbl_dict	itbl_dict[] = {
	{' ', 0, TILE_PATH, NULL},
	{'0', 0, TILE_PATH, NULL},
	{'1', 0, TILE_WALL, NULL},
	{'2', 0, TILE_WATER, NULL},
	{'P', TILE_PLAYER | TILE_ALLY, TILE_PATH, assets->human},
	{'E', TILE_EXIT, TILE_PATH, assets->portal},
	{'C', TILE_COLLECTIBLE, TILE_PATH, assets->coin},
	{'S', TILE_ENEMY, TILE_PATH, assets->slime},
	{'B', TILE_ENEMY, TILE_PATH, assets->bee},
	{'W', TILE_WOLF, TILE_PATH, assets->wolf},
	{'G', TILE_GOBLIN, TILE_PATH, assets->goblin},
	{'L', TILE_PLAYER | TILE_ALLY, TILE_PATH, assets->human},
	{'\0', 0, 0, NULL}};

	ft_memcpy(ret, itbl_dict, sizeof(itbl_dict));
	return (ret);
}

const t_itbl_dict	*ft_get_itbl_hash(t_assets *assets)
{
	static t_itbl_dict	hash[256];
	int					idx;
	const t_itbl_dict	*dict;

	ft_bzero(hash, sizeof(hash));
	dict = ft_get_itbl_dict(assets);
	idx = 0;
	while (dict[idx].key)
	{
		hash[(int)dict[idx].key] = dict[idx];
		idx++;
	}
	return (hash);
}

char	*ft_get_accepted_charset(void)
{
	static char			ret[100];
	const t_itbl_dict	*dict;
	t_assets			dummy;
	int					i;

	dict = ft_get_itbl_dict(&dummy);
	i = 0;
	while (dict[i].key)
	{
		ret[i] = dict[i].key;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_get_enemy_charset(void)
{
	static char			ret[100];
	const t_itbl_dict	*dict;
	t_assets			dummy;
	int					i;

	dict = ft_get_itbl_dict(&dummy);
	i = 0;
	while (dict[i].key)
	{
		if (dict[i].faction && !ft_strchr("PCE", dict[i].key))
		{
			ret[i] = dict[i].key;
			i++;
		}
		else
			dict++;
	}
	ret[i] = '\0';
	return (ret);
}
