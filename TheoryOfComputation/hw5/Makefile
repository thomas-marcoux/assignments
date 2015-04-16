NAME=	parser

CC=	gcc -pthread

CFLAGS=	-c -Wall -g -pthread

RM=	rm -fv

SRC=	parser.c	\
	eval.c		\
	main.c

OBJ=	$(SRC:.c=.o)

all:	$(OBJ)
	$(CC) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
