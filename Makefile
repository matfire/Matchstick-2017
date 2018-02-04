##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=		src/main.c \
			src/board.c \
			src/get_next_line.c \
			src/utils.c \
			src/errors.c \
			src/my_getnbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

CFLAGS	+=	-Wall -Wextra  -I./inc -g

all	:	$(NAME)

$(NAME):			$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean	:
			rm -f $(NAME)

fclean	:	clean
			rm -f $(OBJ)

re	:	fclean all
