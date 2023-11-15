#include "so_long.h"

void ft_sprite_destory(t_sprite *sprite)
{
	if (!sprite)
	{
		ft_printf("WARNING: sprite destory: sprite is null");
		return ;
	}
	free(sprite);
}

void ft_ani_sprite_destory(t_ani_sprite *animated)
{
	int i;

	if (!animated)
	{
		ft_printf("WARNING: ani sprite destory: animated is null");
		return ;
	}
	i = 0;
	while (i < animated->length)
	{
		ft_sprite_destory(animated->sprites_arr[i++]);
	}
	free(animated->sprites_arr);
	free(animated);
}