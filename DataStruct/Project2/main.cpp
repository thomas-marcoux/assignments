#include "tokenList.h"

int	main()
{
  std::string	s("1 + 2 - 4");
  TokenList	*l = new TokenList(s);
  return 0;
}
