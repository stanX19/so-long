#include "so_long.h"

void	ft_image_destory(t_mlx_data * data, t_image * image)
{
	if (data == 0 || data->mlx == 0)
	{
		ft_printf("Null data passed to ft_image_destory\n");
		return ;
	}
	if (image == 0 || image->img == 0)
	{
		ft_printf("Null image passed to ft_image_destory\n");
		return ;
	}
	mlx_destroy_image(data->mlx, image->img);
	free(image);
}