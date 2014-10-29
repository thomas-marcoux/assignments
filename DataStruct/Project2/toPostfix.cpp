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
  if ((top == "+" || top == "-")
      && (tk == "+" || tk == "-"))
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
	for (;!stk.empty() && stk.top() != "("; stk.pop())
	  postfix->addToken(stk.top());
      else
	{
	  for (;!stk.empty() && checkOperand(stk.top(), item); stk.pop()); 
	       postfix->addToken(stk.top());
	  stk.push(item);
	}
    }
  /*
  for (; !stk.empty(); stk.pop())
    std::cout << stk.top() << std::endl;
  */
  return postfix;
}
