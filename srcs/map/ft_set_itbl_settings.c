#include "so_long.h"
#define TOTAL_PARAMS 5

typedef struct s_itbl_settings
{
	int		base_spd;
	t_vec2	offset;
	t_tile	self;
	t_tile	blocking;
} t_itbl_settings;

static void	set_itbl(t_itbl *itbl, const t_itbl_settings params)
{
	itbl->stats.base_speed = params.base_spd;
	itbl->offset = params.offset;
	itbl->self = params.self;
	itbl->blocking = params.blocking;
}

void ft_set_itbl_settings(t_itbl *itbl, t_tile self)
{
	t_itbl_settings params[TOTAL_PARAMS];
	int idx;
	
	params[0] = (t_itbl_settings){0, {0, 0}, TILE_COIN, (TILE_WALL | TILE_WATER)};
	params[1] = (t_itbl_settings){5, {-24, -32}, TILE_PLAYER, (TILE_WALL | TILE_WATER)};
	params[2] = (t_itbl_settings){0, {-4, -8}, TILE_EXIT, (TILE_WALL | TILE_WATER)};
	params[3] = (t_itbl_settings){5, {-16, -16}, TILE_SLIME, (TILE_WALL | TILE_WATER | TILE_SLIME)};
	params[4] = (t_itbl_settings){5, {-16, -16}, TILE_BEE, (TILE_WALL | TILE_BEE)};
	idx = 0;
	while (idx < TOTAL_PARAMS)
	{
		if (params[idx].self == self)
		{
			set_itbl(itbl, params[idx]);
			return ;
		}
		idx++;
	}
	set_itbl(itbl, (t_itbl_settings){0, {0, 0}, 0, 0});
}
#undef TOTAL_PARAMS