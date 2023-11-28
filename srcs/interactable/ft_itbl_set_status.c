#include "so_long.h"

void	ft_itbl_set_status(t_itbl *itbl, t_itbl_status status)
{
	if (itbl->status != status)
	{
		itbl->sprite_idx = 0;
		itbl->frame_tick = 0;
	}
	itbl->status = status;
}