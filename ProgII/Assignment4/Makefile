NAME=	exec

CC=	g++ -pthread

CFLAGS=	-c -Wall -g -pthread

RM=	rm -fv

SRC=	product.cpp		\
	book.cpp		\
	dvd.cpp			\
	thomas_marcoux_main.cpp

OBJ=	$(SRC:.cpp=.o)

all:	$(OBJ)
	$(CC) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
