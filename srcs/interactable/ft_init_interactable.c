#include "so_long.h"

t_stats ft_init_stats(void) {
	t_stats stats;

	stats.damage = 1;
	stats.health = 1;
	stats.max_health = 1;
	stats.speed = 1;
	stats.atk_cd = 10;
	stats.steps = 0;
	stats.stamina = 10;
	stats.max_stamina = stats.stamina;
	stats.velocity = (t_vec2){0, 0};

	return stats;
}

t_itbl * ft_init_interactable(t_ani_sprite *** ani_sprite_tab){
	t_itbl *	ret;

	if (ani_sprite_tab == NULL)
		return NULL;
	ret = malloc(sizeof(t_itbl));
	if (ret == NULL)
		return NULL;
	ret->cord = (t_vec2){0, 0};
	ret->offset = (t_vec2){0, 0};
	ret->rel_cord = (t_vec2){0, 0};
	ret->direction = DOWN;
	ret->status = IDLING;
	ret->animation = ani_sprite_tab[DOWN][IDLE];
	ret->flip = 0;
	ret->sprite_tab = ani_sprite_tab;
	ret->sp_status = IDLE;
	ret->sprite_idx = 0;
	ret->frame_tick = 0;
	ret->blocking = 0;
	ret->stats = ft_init_stats();

	return ret;
}