#ifndef PARSER_H
#define PARSER_H

#define	NB_EXPRS	5
#define NB_OPERATORS	4

#define	VALUE(c)	(c - 48)
#define IS_DIGIT(c)     (c >= 48 && c <= 57)
#define IS_OPERATOR(c)  (c == '+' || c == '-' || c == '*' || c == '/')

typedef struct	op
{
  char	opCode;
  int	(*func)(int, int);
} t_op;

int	eval(char *expr, int leftaddr, int rightaddr);
int	parser(char *expr);

#endif
