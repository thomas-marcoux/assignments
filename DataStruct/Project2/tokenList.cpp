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

#include <iostream>
#include "tokenList.h"

TokenList::TokenList()
  : head(NULL), tail(NULL), valid(true), postfix(false) {}

TokenList::TokenList(std::string& s)
  : head(NULL), tail(NULL), valid(true), postfix(false)
{
  this->parseInput(s);
  if (!(checkTokenList(this)))
    {
      std::cout << "Expression '" << s << "' is invalid" << std::endl;
      this->valid = false;
    }
}

TokenList::~TokenList()
{
  Token	*buff, *it = head;

  while (it)
    {
      buff = it->getNext();
      delete it;
      it = buff;
    }
}

void	TokenList::parseInput(std::string& s)
{
  std::string	buff;
  int	l = s.length();

  for (int i = 0; i < l;)
    {
      if (isToken(s[i]))
	{
	  buff.clear();
	  if (isNum(s[i]))
	    while (isNum(s[i]))
	      buff += s[i++];
	  else
	    buff = s[i++];
	  this->addToken(buff);
	}
      else
	++i;
    }
}

void	TokenList::addToken(Token *t)
{
  if (tail)
    tail->addToken(t);
  else
    head = t;
  tail = t;
}

void	TokenList::addToken(std::string s)
{
  Token	*n = new Token(s);
  this->addToken(n);    
}

Token*	TokenList::getHead() const
{
  return head;
}

bool	TokenList::isValid() const
{
  return valid;
}

bool	TokenList::isPostFix() const
{
  return postfix;
}

void	TokenList::setPostFix()
{
  postfix = true;
}

void	TokenList::print() const
{
  for (Token *it = head; it; it = it->getNext())
    it->print();
  std::cout << std::endl;
}

