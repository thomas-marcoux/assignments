#include <stdio.h>

#define SIZE		5

int	parser(char *expr);

int	main()
{
  int	i;
  char	*s[SIZE] = {"51-62+3+524*-*-", "32+4*53+-5+*62+",
		    "347-49-*-", "334-27-9*+*78*+",
		    "567*-67+2*33++"};
  for (i = 0; i < SIZE; ++i)
    parser(s[i]);
  return 0;
}
