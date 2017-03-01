


NAME = fdf.a

SRCDIR = src

GNLDIR = externals/get_next_line

SRC =   array.c \
        centrate_matrix.c \
        draw.c \
        draw0.c \
        events.c \
        events_get.c \
        main.c \
        matrix.c \
        rotate.c \
        ../$(GNLDIR)/get_next_line.c

OBJ = $($(SRCDIR)/SRC:.c=.o)

LIB_PATH = externals/libft/

LIBOBJ = $(LIB_PATH)*.o

HEAD = -I $(SRCDIR)/FdF.h $(GNLDIR)/get_next_line.h

CFLAGS = -c -Wall -Wextra -Werror

LIBINC = -I $(LIB_PATH)/libft.h -L.$(LIB_PATH) -lft

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_PATH)
    $(OBJ) -lmlx -framework OpenGL -framework AppKit $(NAME) $(LIBOBJ)

%.o: %.c
	gcc $(HEAD) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C $(LIB_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_PATH)

re: fclean all
