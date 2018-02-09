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
			src/player.c \
			src/my_put_nbr.c \
			src/read_player_move_and_print_updated_board_game.c \
			src/ai.c \
			src/print_status.c \
			src/my_getnbr.c

CRIT_SRC	=	bonus/matches_on_line.c \
				bonus/matches_on_board.c \
				bonus/is_number.c \
				bonus/board_gen.c \
				src/utils.c \
				src/errors.c \
				src/my_getnbr.c \
				src/board.c

CRIT_NAME	=	criterion

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

CFLAGS	+=	-Wall -Wextra -Werror -I./inc -g

LDFLAGS = -lcriterion -lgcov --verbose -I./inc

all	:	$(NAME)

$(NAME):			$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean	:
			rm -f $(NAME)

fclean	:	clean
			rm -f $(OBJ)
			rm -f $(CRIT_NAME)

re	:	fclean all

test_run:			$(OBJ)
		cc -o $(CRIT_NAME) $(CRIT_SRC) $(LDFLAGS)
		./$(CRIT_NAME)
