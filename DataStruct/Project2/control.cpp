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

#include <sstream>
#include "tokenList.h"

bool	isNum(char c)
{
  return (c >= 48 && c <= 57);
}

bool	isOpr(char c)
{
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool	isToken(char c)
{
  return ((isNum(c)) || c == '(' || c == ')' ||
	  isOpr(c));
}

bool	isNum(std::string s)
{
  std::istringstream	ss(s);
  int	n;

  if ((ss >> n).fail())
    return false;
  return true;
}

bool	matchingParenthese(const TokenList *tl)
{
  std::string	item;
  int	n = 0;
  for (Token* it = tl->getHead(); it ; it = it->getNext())
    {
      item = it->getItem();
      if (item == ")")
	++n;
      if (item == "(")
	--n;
    }
  return (n) ? false : true;
}

State	transition(std::string tk, State e)
{
  if (e == STATE4)
    {
      if (isNum(tk) && (getNum(tk) == 0))
	return STATE0;
      else
	e = STATE3;
    }
  if ((e == STATE1 || e == STATE3) && tk[0] == '(')
    return STATE1;
  if ((e == STATE1 || e == STATE3) && isNum(tk))
    return STATE2;
  if (e == STATE2 && tk[0] == '/')
    return STATE4;
  if (e == STATE2 && (isOpr(tk[0])))
    return STATE3;
  if (e == STATE2 && tk[0] == ')')
    return STATE2;
  if (e == STATE3 && tk[0] == '(')
    return STATE1;
  return STATE0;
}

bool	checkTokenList(const TokenList *tl)
{
  State	e = STATE1;

  if (!matchingParenthese(tl))
    return false;
  for (Token* it = tl->getHead(); it && (e = transition(it->getItem(), e)); it = it->getNext());
  return (e == STATE2);
}
