##
## EPITECH PROJECT, 2023
## makefile
## File description:
## pour my_printf
##

CC	=	gcc	-Wall -Wextra -g3

SRC	=	src/main.c	\
		src/my_putstr.c	\
		src/my_putchar.c	\
		src/my_strcmp.c		\
		src/help_func.c		\
		src/split_string.c	\
		src/error_func.c	\
		src/init_all.c		\
		src/init_obj.c		\
		src/to_number.c		\
		src/init_plane.c	\
		src/game.c			\
		src/mouv_plane.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_radar

COMP	=	-o $(NAME)

CFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS	+= -iquote include

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(COMP) $(CFLAGS) $(OBJ)
clean:
	rm -f $(OBJ)
	rm -f *#
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
