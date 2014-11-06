NAME=	calc

CC=	g++ -pthread

CFLAGS=	-c -Wall -g -pthread

RM=	rm -fv

SRC=	token.cpp		\
	tokenList.cpp		\
	control.cpp		\
	toPostfix.cpp		\
	eval.cpp		\
	main.cpp

OBJ=	$(SRC:.cpp=.o)

all:	$(OBJ)
	$(CC) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
