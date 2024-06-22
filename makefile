SRCDIR		= srcs
SRCS		:= $(shell find $(SRCDIR) -name '*.c')

OBJDIR		= objs
OBJDIRS		= $(sort $(dir $(OBJS)))
OBJS		= $(subst $(SRCDIR),$(OBJDIR),$(subst .c,.o,$(SRCS)))

CWD			:= $(shell pwd)
INCLUDE_DIR	= includes
HEADER_DIR	= headers
HEADERS		:= $(shell find $(HEADER_DIR) -name '*.h') $(shell find $(INCLUDE_DIR) -name '*.h')
HEADERS_INC	= $(addprefix -I,$(sort $(dir $(HEADERS))))

UNAME_S		:= $(shell uname -s)
MLX_LINUX	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_MACOS	= -lmlx -framework OpenGL -framework AppKit
ifeq ($(UNAME_S), Darwin)
	MLX		= $(MLX_MACOS)
	MLX_CO	=
else
	MLX		= $(MLX_LINUX)
	MLX_CO	= $(MLX_LINUX)
endif

LIBFT_DIR	= $(INCLUDE_DIR)/libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBS		= $(LIBFT)

IFLAGS		:= -I. $(HEADERS_INC)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror #-fsanitize=address -g3
AR			= ar -rcs
RM			= rm -rf
UP			= \033[1A
FLUSH		= \033[2K

NAME		= so_long
ARGV		= \
map/map0.ber\
map/map1.ber\
map/map2.ber

run: all
	./$(NAME) $(ARGV)

$(NAME): $(LIBS) $(OBJDIRS) $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) $(LIBS) $(MLX) -o $(NAME)

bonus: $(NAME)

all: $(NAME)

$(OBJDIRS):
	mkdir -p $@
	@echo "$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(IFLAGS) $(MLX_CO) -c $< -o $@
	@echo "$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)$(FLUSH)$(UP)"

clean:
	@$(RM) $(OBJS)

fclean:	clean
	make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
	@$(RM) $(TESTDIR)
	@$(RM) $(OBJDIRS)
	@$(RM) ./a.out

re: fclean $(NAME)

push:
	@echo -n "Commit name: "; read name; make fclean;\
	git add .; git commit -m "$$name"; git push;\
	cd $(LIBFT_DIR); git add .; git commit -m "$$name"; git push;

BRANCH := $(shell git rev-parse --abbrev-ref HEAD)
ifeq ($(BRANCH),HEAD)
BRANCH := main
endif
pull:
	git fetch --all
	git checkout -f $(BRANCH);
	git reset --hard origin/$(BRANCH);
	make -C $(LIBFT_DIR) pull

$(LIBFT): $(LIBFT_DIR) $(shell find $(LIBFT_DIR) -name "*.c")
	make -C $(LIBFT_DIR) all

$(LIBFT_DIR):
	touch .gitmodules
	git submodule add --force git@github.com:stanX19/libft.git $(LIBFT_DIR)
	git config -f .gitmodules submodule.$(LIBFT_DIR).branch main
	git submodule update --init --recursive --remote

init_libft: $(LIBFT_DIR)

xpm:
	find . -type f -name "*.xpm" -exec $(RM) {} \;
	mogrify -format xpm ./assets/*/*/*.png
	@make path_h

ASSETS_PATH_H	= headers/assets_path.h
path_h:
	@echo "#ifndef ASSETS_PATH_H" > $(ASSETS_PATH_H)
	@echo "# define ASSETS_PATH_H" >> $(ASSETS_PATH_H)
	@find assets/ -type f -name '*.xpm' -exec sh -c ' \
		FILE="{}"; \
		DEF_NAME=$$(echo "$$FILE" | tr "/" "_" | sed "s/\.xpm$$//" | awk "{print toupper(\$$0)}" | sed "s/ASSETS_SPRITES_//"  | sed "s/ASSETS__SPRITES_//"); \
		echo "# define PATH_$$DEF_NAME \"$$FILE\"" >> $(ASSETS_PATH_H); \
	' \;
	@echo "#endif" >> $(ASSETS_PATH_H)
	@cat $(ASSETS_PATH_H)


.PHONY: all clean fclean re bonus push
