#include <stack>
#include "token.h"
#include "tokenList.h"

Token*	toPostfix(TokenList& tl)
{
  std::stack<std::string>	stk;

  tl.addToken(std::string(")"));
  tl.print();
  return new Token("2");
}
