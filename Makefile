##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	$(shell find src -name "*.c")

OBJ	=	$(SRC:.c=.o)

NAME	=	hunter

CFLAGS 	=	-Wall -Wextra -g

CSFML_FLAGS = -lcsfml-system -lcsfml-graphics -lcsfml-window \
-lcsfml-audio -lcsfml-network -lm

all: compile

compile: $(OBJ)
	gcc $(OBJ) -o $(NAME) -iquote include/ $(CSFML_FLAGS)

clean:
	rm -f $(wildcard src/*~)
	rm -f $(wildcard src/*#)

fclean: clean
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all

.PHONY: compile clean fclean re

