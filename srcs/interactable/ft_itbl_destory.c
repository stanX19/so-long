#include "so_long.h"

static void	sprite_tab_destory(t_ani_sprite ***	sprite_tab)
{
	for (int i = 0; i < NUM_DIRECTIONS; i++)
	{
		free(sprite_tab[i]);
	}
	free(sprite_tab);
}

void	ft_itbl_destory(t_itbl *itbl)
{
	sprite_tab_destory(itbl->sprite_tab);
	free(itbl);
}