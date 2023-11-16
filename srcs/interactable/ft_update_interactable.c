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
		return IDLE;
	default:
		return itbl->status;
	}
}
static void	update_frame_tick(t_itbl * itbl, t_ani_sprite * animated)
{
	if (!animated)
	{
		itbl->status = get_next_state(itbl);
		return ;
	}
	if (itbl->frame_tick >= animated->frame_interval)
	{
		itbl->frame_tick = 0;
		++itbl->sprite_idx;
	}
	if (itbl->sprite_idx >= animated->length)
	{
		itbl->sprite_idx = 0;
		itbl->status = get_next_state(itbl);
	}
	++itbl->frame_tick;
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

void ft_update_itbl_status(t_itbl * itbl)
{	
	if (itbl->status == DEAD)
	{
		itbl->animation = 0;
		return ;
	}
	itbl->sp_status = get_sprite_status(itbl->status);
	itbl->animation = itbl->sprite_tab[itbl->direction][itbl->sp_status];
	check_flip(itbl);
	update_frame_tick(itbl, itbl->animation);
	if (itbl->status == DEAD)
	{
		itbl->animation = 0;
		return ;
	}
}