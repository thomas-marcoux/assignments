NAME=	metacompiler

META=	.language.meta

CC=	g++

CFLAGS=	-c -Wall -g

RM=	rm -fv

SRC=	main_meta.cpp

OBJ=	$(SRC:.cpp=.o)

all:	$(OBJ)
	$(CC) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME) $(META)

re:	fclean all
