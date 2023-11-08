SRCDIR	= srcs/
SPRITE	= sprite/
IMAGE	= image/
MAP		= map/
UTILS	= utils/
MLXUTILS	= mlx_utils/
SRCS	=	$(addsuffix .c, \
		$(addprefix $(SRCDIR)ft_, \
			) \
		$(addprefix $(SRCDIR)$(IMAGE)ft_, \
			read_xpm new_image fill_image\
			mlx_put_image_to_win)\
		$(addprefix $(SRCDIR)$(MAP)ft_, \
			is_valid_map generate_raw_map\
			initialize_map initialize_map_sprites\
			initialize_map_cords)\
		$(addprefix $(SRCDIR)$(MLXUTILS)ft_, \
			mlx_init mlx_pixel_put)\
		$(addprefix $(SRCDIR)$(UTILS)ft_, \
			memcpy strdup)\
		$(addprefix $(SRCDIR)$(SPRITE)ft_, \
			init_sprite mlx_put_sprite\
			generate_sprites_array init_animated_sprite)\
			)

OBJDIR		= objs/
OBJDIRS		= $(sort $(dir $(OBJS)))
OBJS		= $(subst $(SRCDIR),$(OBJDIR),$(subst .c,.o,$(SRCS)))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address
RM			= rm -rf
TESTDIR		= so_long_tester
TESTGIT		= https://github.com/augustobecker/so_long_tester.git
MLX_LINUX	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_MACOS	= -Lmlx_macos -lmlx -framework OpenGL -framework AppKit
MLX			= $(MLX_LINUX)
NAME		= so_long

run: re
	./$(NAME)
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) main.c -I. $(MLX) -o $(NAME)
	
$(OBJDIRS):
	mkdir -p $@
objs/%.o: srcs/%.c | $(OBJDIRS)
	$(CC) $(CFLAGS) $(MLX) -I. -c $< -o $@
	@echo -e "\033[1A\033[2K\033[1A"
clean:
	@$(RM) $(OBJS)
	
fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(TESTDIR)
	@$(RM) ./a.out
re:	fclean $(NAME)

test: $(TESTDIR)
	cd $(TESTDIR) && make && make fclean
$(TESTDIR):
	git clone $(TESTGIT)
.PHONY:			all clean fclean re .c.o
