NAME = so_long
SRC_FILES = check_map.c \
            check_map_2.c \
            check_position.c \
            get_background.c \
            get_image.c \
            get_next_line.c \
            get_next_line_utils.c \
            main.c \
            make_map.c \
            make_map_2.c \
            utils_map.c \
            utils_map_2.c \
            utils.c \
            
OBJECTS = $(patsubst %.c, %.o, $(SRC_FILES))
INCLUDE = so_long.h
CC = cc 
FLAGS = -Wall -Wextra -Werror -O3 -g3
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a
MLX_INCLUDE = -L/usr/lib/X11 -lXext -lX11 libmlx.a

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(LIBFT_PATH)
	@$(CC) $(FLAGS) $(OBJECTS) $(LIBFT) $(MLX_INCLUDE) -o $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(FLAGS) -I$(LIBFT_PATH) -Imlx.h -c $< -o $@

clean:
	@make clean -C $(LIBFT_PATH)
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
