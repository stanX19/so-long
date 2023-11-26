#include "so_long.h"

static t_sprite_status get_sprite_status(t_itbl_status status)
{
	switch (status)
	{
	case DYING:
		return DEATH;
	case IDLING:
		return IDLE;
	case MOVING:
		return WALK;
	case ATTACKING:
		return ATTACK;
	default:
		return IDLE;
	}
}

static t_itbl_status get_next_state(t_itbl * itbl)
{
	switch (itbl->status)
	{
	case DYING:
		return DEAD;
	case ATTACKING:
		return IDLING;
	default:
		return itbl->status;
	}
}

static void check_flip(t_itbl * itbl)
{
	if ((itbl->direction == RIGHT && !itbl->animation &&
		itbl->sprite_tab[LEFT][itbl->sp_status]) ||
		(itbl->direction == LEFT && !itbl->animation &&
		itbl->sprite_tab[RIGHT][itbl->sp_status]))
	{
		itbl->animation = itbl->sprite_tab[LEFT][itbl->sp_status];
		itbl->flip = 1;
	}
	else
		itbl->flip = 0;
}

static void set_animation(t_itbl *itbl)
{
	if (itbl->status == DEAD)
	{
		itbl->animation = 0;
		return ;
	}
	itbl->sp_status = get_sprite_status(itbl->status);
	itbl->animation = itbl->sprite_tab[itbl->direction][itbl->sp_status];
	check_flip(itbl);
}

void ft_update_itbl_status(t_itbl * itbl)
{
	set_animation(itbl);
	++itbl->frame_tick;
	if (!itbl->animation)
	{
		return ;
	}
	if (itbl->frame_tick >= itbl->animation->frame_interval)
	{
		itbl->frame_tick = 0;
		++itbl->sprite_idx;
	}
	if (itbl->sprite_idx >= itbl->animation->length)
	{
		itbl->sprite_idx = 0;
		itbl->status = get_next_state(itbl);
		set_animation(itbl);
	}
}