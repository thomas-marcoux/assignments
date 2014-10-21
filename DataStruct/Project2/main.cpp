#include "tokenList.h"

int	main()
{
  std::string	s("1 + 2 - 4");
  TokenList	l = TokenList(s);
  toPostfix(l);
  return 0;
}
