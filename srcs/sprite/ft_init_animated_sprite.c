#include "so_long.h"

t_ani_sprite* ft_init_animated_sprite(t_sprite** sprites, int length, int frame_interval){
	t_ani_sprite*	animated;

	animated = malloc(sizeof(t_ani_sprite));
	animated->sprites_arr = sprites;
	animated->length = length;
	animated->frame_interval = frame_interval;

	return animated;
}