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

void	popParenthese(std::stack<std::string> &stk, TokenList *postfix)
{
  for (;!stk.empty() && stk.top() != "("; stk.pop())
    postfix->addToken(stk.top());
  stk.pop();
}

void	popOperands(std::stack<std::string> &stk, TokenList *postfix,
		    std::string item, Token* it)
{
  for (;!stk.empty() && checkOperand(stk.top(), item); stk.pop())
    postfix->addToken(stk.top());
  if (it)
    stk.push(item);
}

TokenList*	toPostfix(TokenList& tl)
{
  TokenList	*postfix = new TokenList();
  std::stack<std::string>	stk;
  std::string	item = "";

  stk.push(std::string("("));
  tl.addToken(std::string(")"));
  for (Token* it = tl.getHead(); !stk.empty();)
    {
      if (it)
	item = it->getItem();
      if (item == "(")
	stk.push(item);
      else if (isNum(item))
	postfix->addToken(item);
      else if (item == ")")
	popParenthese(stk, postfix);
      else
	popOperands(stk, postfix, item, it);
      if (it)
	it = it->getNext();
    }
  return postfix;
}
