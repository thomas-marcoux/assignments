#include <string.h>
#include <stdio.h>
#include "parser.h"

int	isValid(char *c)
{
  int	i, j;

  for (i = 0, j = 0; c[i]; ++i)
    {
      if (!IS_DIGIT(c[i]) && !IS_OPERATOR(c[i]))
	return 2;
      IS_DIGIT(c[i]) ? ++j : --j;
      if (j < 1)
	return 0;
    }
  return (j == 1);
}

int	parser(char *expr)
{
  int	ret, value;
  char	*ret_message[3] = {"has mismatched operators",
			   "is valid", "contains illegal characters"};
  ret = isValid(expr);
  printf("%s %s\n", expr, ret_message[ret]);
  if (ret != 1)
    return 0;
  value = eval(expr, 0, strlen(expr) - 1);
  printf(" = %d\n", value);
  return 1;
}
