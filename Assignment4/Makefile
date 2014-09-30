NAME=threads

CC=gcc

CFLAGS=	-c -Wall -g

RM=	rm -fv

SRC=	main.c

OBJ=	$(SRC:.c=.o)

all:	$(OBJ)
	$(CC) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
