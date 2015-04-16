#include <stdio.h>

int	eval(char *expr);

int	isOperator(char c)
{
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

int	isDigit(char c)
{
  return (c >= 48 && c <= 57);
}

int	isValid(char *c)
{
  int	i, j;

  for (i = 0, j = 0; c[i]; ++i)
    {
      if (!isDigit(c[i]) && !isOperator(c[i]))
	return 2;
      isDigit(c[i]) ? ++j : --j;
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
  value = eval(expr);
  printf("%s = %d\n", expr, value);
  return 1;
}
