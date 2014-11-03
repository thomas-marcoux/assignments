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
#include <stack>
#include "tokenList.h"

int	getNum(std::string s)
{
  std::istringstream	ss(s);
  int	n;

  ss >> n;
  return n;
}

void	eval(char opt, std::stack<int> &stk)
{
  int	n1;
  int	n2;

  n2 = stk.top();
  stk.pop();
  n1 = stk.top();
  stk.pop();
  if (opt == '+')
    stk.push(n1 + n2);
  if (opt == '-')
    stk.push(n1 - n2);
  if (opt == '*')
    stk.push(n1 * n2);
  if (opt == '/')
    stk.push(n1 / ((n2 == 0) ? 1 : n2));
}

int	evalPostfix(TokenList *postFix)
{
  if (!postFix->isPostFix())
    return 0;
  std::string	item;
  std::stack<int>	stk;
  char	c;
  int	n;

  for (Token *it = postFix->getHead(); it; it = it->getNext())
    {
      item = it->getItem();
      if (isNum(item))
	{
	  n = getNum(item);
	  c = '$';
	}
      else
	c = item[0];
      switch (c)
	{
	case '$':
	  stk.push(n);
	  break;
	default:
	  eval(c, stk);
	}
    }
  return stk.top();
}
