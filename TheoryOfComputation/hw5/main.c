#include "parser.h"

int	main()
{
  int	i;
  char	*s[NB_EXPRS] = {"51-62+3+524*-*-", "32+4*53+-5+*62+",
			"347-49-*-", "334-27-9*+*78*+",
			"567*-67+2*33++"};
  for (i = 0; i < NB_EXPRS; ++i)
    parser(s[i]);
  return 0;
}
