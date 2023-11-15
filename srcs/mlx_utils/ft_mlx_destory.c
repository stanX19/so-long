#include "so_long.h"

void	ft_mlx_destory(t_mlx_data * data)
{
	if (data == 0)
	{
		ft_printf("WARNING: mlx destory: null pointer passed in");
		return ;
	}
	mlx_destroy_window(data->mlx, data->mlx_win);
	
	for (int i = 0; i < data->all_img.idx; i++)
	{
		ft_image_destory(data, data->all_img.arr[i]);
	}
	for (int i = 0; i < data->all_ani_sprite.idx; i++)
	{
		ft_ani_sprite_destory(data->all_ani_sprite.arr[i]);
	}
	free(data->mlx);
	free(data);
}