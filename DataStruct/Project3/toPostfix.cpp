/* CPSC2380 
 * Department of Computer Science, UALR 
 * Project 3
 * Student Name: Thomas Marcoux
 * Student UALR ID (last four digits): 5564
 * Project Descriptions: 
 * This project takes an arithmetic expression as input,
 * converts it to postfix, then to a binary tree which it prints
 * along with its infix, postfix and prefix expression
 * as well as the evaulation of the tree.
 * Project Due Date: 12/4/2014 
 * Project Revised Date: 11/30/2014, 12/03/2014 
 */

#include <stack>
#include "tokenList.h"

//Returns a boolean according to operator priority
bool	checkOperator(std::string top, std::string tk)
{
  if (top == "*" || top == "/")
    return true;
  if ((top == "+" || top == "-")
      && (tk == "+" || tk == "-"))
    return true;
  return false;
}

//Add tokens from stk to postfix until it meets an opening parenthese
void	popParenthese(std::stack<std::string> &stk, TokenList *postfix)
{
  for (;!stk.empty() && stk.top() != "("; stk.pop())
    postfix->addToken(stk.top());
  stk.pop();
}

//Add operators from stk to postfix according to operator priority
void	popOperators(std::stack<std::string> &stk, TokenList *postfix,
		    std::string item, Token* it)
{
  for (;!stk.empty() && checkOperator(stk.top(), item); stk.pop())
    postfix->addToken(stk.top());
  if (it)
    stk.push(item);
}

//Returns the conversion of infix to postfix
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
	popOperators(stk, postfix, item, it);
      if (it)
	it = it->getNext();
    }
  postfix->setPostFix();
  return postfix;
}

