/* CPSC2380 
 * Department of Computer Science, UALR 
 * Project 2 
 * Student Name: Thomas Marcoux
 * Student UALR ID (last four digits): 5564
 * Project Descriptions: 
 * This project takes an arithmetic expression as input,
 * converts it to postfix and evaluates it, outputting the result.
 * Project Due Date: 11/4/2014 
 * Project Revised Date: 8/30/2014, 11/3/2014 
 */

#include <stack>
#include "tokenList.h"

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

TokenList*	toPostfix(TokenList *infix)
{
  if (!infix->isValid())
    return NULL;
  TokenList	*postfix = new TokenList();
  std::stack<std::string>	stk;
  std::string	item = "";

  stk.push(std::string("("));
  infix->addToken(std::string(")"));
  for (Token* it = infix->getHead(); !stk.empty();)
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
  postfix->setPostFix();
  return postfix;
}

