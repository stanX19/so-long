#include "so_long.h"

void	ft_image_destory(t_assets * assets, t_image * image)
{
	if (assets == 0 || assets->mlx == 0)
	{
		ft_printf("Null data passed to ft_image_destory\n");
		return ;
	}
	if (image == 0 || image->img == 0)
	{
		ft_printf("Null image passed to ft_image_destory\n");
		return ;
	}
	mlx_destroy_image(assets->mlx, image->img);
	free(image);
}