NAME=	template

CC=	g++

CFLAGS=	-Wall -c -g

RM=	rm -fv

SRC=	main.cpp

OBJ=	$(SRC:.cpp=.o)

all:	$(OBJ)
	$(CC) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re