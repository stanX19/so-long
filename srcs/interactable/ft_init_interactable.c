#include "so_long.h"

t_stats ft_init_stats(void) {
	t_stats stats;

	stats.damage = 1;
	stats.health = 1;
	stats.max_health = 1;
	stats.speed = 1;
	stats.atk_cd = 10;

	return stats;
}

t_interactable * ft_init_interactable(t_ani_sprite*** sprite_tab){
	t_interactable *	ret;

	if (sprite_tab == NULL)
		return NULL;
	ret = malloc(sizeof(t_interactable));
	if (ret == NULL)
		return NULL;
	ret->loc = (t_vec2){0, 0};
	ret->rel_cords = (t_vec2){0, 0};
	ret->direction = DOWN;
	ret->status = IDLE;
	ret->sprite_tab = sprite_tab;
	ret->sprite_idx = 0;
	ret->stats = ft_init_stats();

	return ret;
}