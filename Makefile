


NAME = FdF.a

SRC =   main.c \
        FdF.c

OBJ = $(SRC:.c=.o)

LIB_PATH = ../../LIBFT/

LIBOBJ = $(LIB_PATH)*.o

HEAD = -I FdF.h

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
