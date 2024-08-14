##
## June 2024
## Magdalena Martinez Sanchez
## NAVY_GAME
## Makefile
##

NAME	=	mines_game



INCLUDE	=	-I ./include/

SRC	= 	src/main.c	\
		src/utilities.c \
		src/map.c \
		src/ncurses.c \
		src/calculate.c \
	

OBJ	=	$(SRC:.c=.o)


all: 	$(NAME)

$(NAME): 	$(OBJ)

		gcc -g $(OBJ) -o $(NAME) $(INCLUDE) -lncurses

clean:
	rm -f $(NAME)


fclean: clean
	rm -f ./src/*.o

re: 	fclean all

library: fclean

exec:	re
	./$(NAME)
