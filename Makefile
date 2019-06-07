##
## EPITECH PROJECT, 2017
## project
## File description:
## project
##

SRC 	=	src/main.c \
			src/my_str_to_array.c \
			src/solver.c

NAME 	=	solver

OBJ	=	$(SRC:.c=.o)

CFLAGS  =	-Iinclude/

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
