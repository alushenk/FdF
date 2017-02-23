


NAME = FdF.a

SRCDIR = src

SRC =   main.c \
        FdF.c \
        array.c \
        draw.c \
        matrix.c \
        events.c \
        externals/get_next_line/get_next_line.c

OBJ = $($(SRCDIR)/SRC:.c=.o)

LIB_PATH = externals/libft/

LIBOBJ = $(LIB_PATH)*.o

HEAD = -I $(SRCDIR)/FdF.h

CFLAGS = -c -Wall -Wextra -Werror

LIBINC = -I $(LIB_PATH)/libft.h -L.$(LIB_PATH) -lft

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_PATH)
	ar rc $(NAME) $(OBJ) $(LIBOBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(HEAD) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C $(LIB_PATH)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_PATH)

re: fclean all
