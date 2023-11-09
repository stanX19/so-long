#include "so_long.h"

t_ani_sprite* ft_init_animated_sprite(t_sprite** sprites, int length, int frame_interval){
	t_ani_sprite*	animated;

	if (sprites == NULL)
		return 0;
	animated = malloc(sizeof(t_ani_sprite));
	if (animated == NULL)
		return 0;
	animated->sprites_arr = sprites;
	animated->length = length;
	animated->frame_interval = frame_interval;

	return animated;
}