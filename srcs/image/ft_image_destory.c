#include "so_long.h"

void	ft_image_destory(t_image * image)
{
	if (image == 0 || image->img == 0)
	{
		ft_printf("Null image passed to ft_image_destory\n");
		return ;
	}
	mlx_destroy_image(image->mlx, image->img);
	free(image);
}