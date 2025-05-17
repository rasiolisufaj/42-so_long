#----		PROJECT		----#
NAME = so_long

#----		COMPILER		----#
CC = clang
CC_FLAGS = -Wall -Wextra -Werror

#----		COMMANDS		----#
RM = rm -rf

#----		DIRECTORIES		----#
OBJ_DIR = .objFiles
SRC_DIR = srcs
INC_DIR = includes
LIBFT_DIR = libft
MLX_DIR = minilbx

#----		FILES		----#
SRC_FILES := $(shell find $(SRC_DIR) -name "*.c")
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
INC_FILES := $(wildcard $(INC_DIR)/*.h)

#----		LIBRARIES		----#
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
LIBFT_INC = $(LIBFT_DIR)/includes
L_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

.PHONY: all clean fclean re norminette

#----		RULES		----#
all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) ${CC_FLAGS} $(OBJ_FILES) -L$(LIBFT_DIR) ${L_FLAGS} -I$(MLX_DIR) -I$(INC_DIR) -lft -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	mkdir -p $(dir $@)
	$(CC) $(CC_FLAGS) -I $(INC_DIR) -I $(LIBFT_INC) -I $(MLX_DIR) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@clear

$(MLX):
	@make -C $(MLX_DIR)
	@clear

clean:
	$(RM) $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all