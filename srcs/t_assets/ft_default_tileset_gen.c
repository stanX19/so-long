#include "so_long.h"

typedef struct s_vars2
{
	t_image *img;
	t_vec2 size;
	int y;
	int x;
	unsigned int color_0;
	unsigned int color_1;
} t_vars2;

static unsigned int get_color(t_vars2 *vars, int x, int cmp)
{
	return vars->color_0 * (!(x & cmp)) + vars->color_1 * ((x & cmp) == cmp);
}

static void fill_tile_fmt(t_vars2 *vars, t_vec2 start, t_vec2 space, int idx)
{
    t_vec2 end;

    switch (idx)
    {
    case 1:
        start.x += space.x;
        break;
    case 2:
        start.y += space.y;
        break;
    case 3:
        start.x += space.x;
        start.y += space.y;
    }
    end = start;
    end.x += space.x;
    end.y += space.y;
    ft_fill_image(vars->img, get_color(vars, vars->x, 1 << (3 - idx)), start, end);
}

static void paint_tile(t_vars2 vars)
{
    t_vec2 start;
    t_vec2 space;

    start.y = vars.img->height / vars.size.y * vars.y;
    space.x = vars.img->width / vars.size.x / 2;
    space.y = vars.img->height / vars.size.y / 2;
	vars.x = 0;
    while (vars.x < vars.size.x)
    {
        start.x = vars.img->width / vars.size.x * vars.x;
        fill_tile_fmt(&vars, start, space, 0);
		fill_tile_fmt(&vars, start, space, 1);
		fill_tile_fmt(&vars, start, space, 2);
		fill_tile_fmt(&vars, start, space, 3);
        vars.x++;
    }
}

t_image* ft_default_tileset_gen(t_assets *assets, t_vec2 size)
{
	t_image *img;

	img = ft_new_image(assets, size.x * 16, size.y * 16);
	paint_tile((t_vars2){img, size, 0, 0, COLOR_FOREST_GREEN, COLOR_TREE_GREEN});
	paint_tile((t_vars2){img, size, 1, 0, COLOR_LIGHT_SEA_GREEN, COLOR_GRASS});
	paint_tile((t_vars2){img, size, 2, 0, COLOR_DARK_OLIVE_GREEN, COLOR_DARK_GREEN});
	paint_tile((t_vars2){img, size, 3, 0, COLOR_LAND, COLOR_GRASS});
	return img;
}