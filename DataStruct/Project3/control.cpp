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

//Returns true if the char c is part of a mathematical expression
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

//Returns true if the TokenList tl has a valid number of parentheses
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

//Check that the TokenList's grammar is correct
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

//Runs control functions on the TokenList tl to test its validity
bool	checkTokenList(const TokenList *tl)
{
  State	e = STATE1;

  if (!matchingParenthese(tl))
    return false;
  for (Token* it = tl->getHead();
       it && (e = transition(it->getItem(), e)); it = it->getNext());
  return (e == STATE2);
}
