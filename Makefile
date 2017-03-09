NAME = FdF

SRCDIR = src

GNLDIR = externals/get_next_line

SRC =	array.c \
		centrate_matrix.c \
		draw.c \
		draw0.c \
		errors.c \
		events.c \
		events_get.c \
		main.c \
		matrix.c \
		rotate.c \

GNL =	get_next_line.c

OBJ = $(addprefix $(SRCDIR)/, $(SRC:.c=.o)) $(addprefix $(GNLDIR)/, $(GNL:.c=.o))

LIB_PATH = $(GNLDIR)/libft

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_PATH)
	gcc -o $(NAME) $(OBJ) $(LIB_PATH)/libft.a -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	gcc -c -Wall -Wextra -Werror -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C $(LIB_PATH)

fclean:
	rm -f $(NAME)
	rm -f $(OBJ)
	make fclean -C $(LIB_PATH)

re: fclean all
