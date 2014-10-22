#include "tokenList.h"

TokenList*	toPostfix(TokenList& tl);

int	main()
{
  std::string	s("1 + 2 - 4");
  TokenList	l = TokenList(s);
  (toPostfix(l))->print();;
  return 0;
}
