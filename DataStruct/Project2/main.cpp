#include "tokenList.h"

TokenList*	toPostfix(TokenList& tl);

int	main()
{
  std::string	s[] = {
      "1 + 2 - 4",
      "10 * ( 2 + 3 )",
      "10 / 3 + 2 - 5 * ( 2 - 3 ) + 45",
      "3 - 4 5",
    "( 2 * 3 ) + ( 5 - ( 3 * 2 ) )"
  };
  TokenList	*postFix;
  for (int i = 0; i < 5; ++i)
    {
      TokenList	l = TokenList(s[i]);
      l.print();
      postFix = toPostfix(l);
      postFix->print();
      delete postFix;
    }
  return 0;
}
