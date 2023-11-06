SRCDIR	= srcs/
SPRITE	= sprite/
MAP		= map/
UTILS	= utils/
MLXUTILS	= mlx_utils/
SRCS	=	$(addsuffix .c, \
		$(addprefix $(SRCDIR)ft_, \
			) \
		$(addprefix $(SRCDIR)$(SPRITE)ft_, \
			init_sprite)\
		$(addprefix $(SRCDIR)$(MAP)ft_, \
			is_valid_map generate_raw_map initialize_map)\
		$(addprefix $(SRCDIR)$(UTILS)ft_, \
			memcpy strdup)\
		$(addprefix $(SRCDIR)$(MLXUTILS)ft_, \
			mlx_init mlx_pixel_put))

OBJS		=	$(subst .c,.o,$(SRCS))

CC			= 	gcc
CFLAGS		=	-Wall -Wextra -Werror#-fsanitize=address
RM			=	rm -rf
TESTDIR		= so_long_tester
TESTGIT		= https://github.com/augustobecker/so_long_tester.git
MLX_LINUX	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_MACOS	= -Lmlx_macos -lmlx -framework OpenGL -framework AppKit
MLX			= $(MLX_MACOS)
NAME		= so_long

run: re
	./$(NAME)
all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) main.c -I. $(MLX) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -I. -c $< -o $@
	@echo "\033[1A\033[2K\033[1A"
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
