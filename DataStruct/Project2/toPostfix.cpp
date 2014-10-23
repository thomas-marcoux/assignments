#include <iostream>
#include <sstream>
#include <stack>
#include "token.h"
#include "tokenList.h"

bool	isNum(std::string s)
{
  std::istringstream	ss(s);
  int	n;

  if ((ss >> n).fail())
    return false;
  return true;
}

bool	checkOperand(std::string top, std::string tk)
{
  if (top == "*" || top == "/")
    return true;
  return false;
}

TokenList*	toPostfix(TokenList& tl)
{
  TokenList	*postfix = new TokenList();
  std::stack<std::string>	stk;
  std::string	item;

  stk.push(std::string("("));
  tl.addToken(std::string(")"));
  for (Token* it = tl.getHead(); !(stk.empty()) && it; it = it->getNext())
    {
      item = it->getItem();
      if (item == "(")
	stk.push(item);
      else if (isNum(item))
	postfix->addToken(item);
      else if (item == ")")
	for (std::string c = stk.top(); c != "("; stk.pop(), c = stk.top())
	  postfix->addToken(c);
      else
	{
	  for (std::string c = stk.top(); !stk.empty() && checkOperand(c, item); stk.pop(), c = stk.top())
	    postfix->addToken(c);
	  stk.push(item);
	}
    }
  return postfix;
}
