#include "parser.h"

int	add(int n1, int n2) {
  return n1 + n2;
}

int	sub(int n1, int n2) {
  return n1 - n2;
}

int	mul(int n1, int n2) {
  return n1 * n2;
}

int	div(int n1, int n2) {
  return n1 / n2;
}

t_op	table[NB_OPERATORS] = {
  {'+', &add},
  {'-', &sub},
  {'*', &mul},
  {'/', &div}
};

int	getMid(char *expr, int leftaddr, int rightaddr)
{
  int	mid, i;

  for (i = 0; leftaddr < rightaddr; ++leftaddr)
    {
      IS_DIGIT(expr[leftaddr]) ? ++i : --i;
      if (i == 1)
	mid = leftaddr;
    }
  return mid;
}

int	eval(char *expr, int leftaddr, int rightaddr)
{
  int	mid, i;

  if (leftaddr == rightaddr)
    return VALUE(expr[leftaddr]);
  mid = getMid(expr, leftaddr, rightaddr);
  for (i = 0; i < NB_OPERATORS; ++i)
    if (table[i].opCode == expr[rightaddr])
      return table[i].func(eval(expr, leftaddr, mid),
			   eval(expr, mid + 1, rightaddr - 1));
  return 0;
}
