#include "so_long.h"

void ft_itbl_update_direction(t_itbl *itbl)
{
	if (itbl->velocity.x > 0)
		itbl->direction = RIGHT;
	else if (itbl->velocity.x < 0)
		itbl->direction = LEFT;
	else if (itbl->velocity.y > 0)
		itbl->direction = DOWN;
	else if (itbl->velocity.y < 0)
		itbl->direction = UP;
}