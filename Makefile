##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Compilation of libcuddle.a
##

SRC     =   src/start.c    \
            src/init_data.c 	\
			src/check_type.c	\
			src/df_info.c	\
			src/df_shape.c	\
			src/df_describe.c	\
			src/fill_row.c

OBJ     =   $(SRC:.c=.o)

NAME    =   libcuddle.a

CC      =   gcc

IFLAGS  =   -Iinclude/
CFLAGS  =   -Wall -Wextra -g3 $(IFLAGS) -lm

LIBMY   =   lib/my/libmy.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBMY)
	ar rcs $(NAME) $(OBJ) $(LIBMY)

$(LIBMY):
	$(MAKE) -C lib/my

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C lib/my
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C lib/my
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
