NAME=	metacompiler

CC=	g++

CFLAGS=	-c -Wall -g

RM=	rm -fv

SRC=	language.cpp		\
	main.cpp

OBJ=	$(SRC:.cpp=.o)

all:	$(OBJ)
	$(CC) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
