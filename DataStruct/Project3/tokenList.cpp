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

#include <iostream>
#include "tokenList.h"

TokenList::TokenList()
  : head(NULL), tail(NULL), valid(true), postfix(false) {}

TokenList::TokenList(std::string& s)
  : head(NULL), tail(NULL), valid(true), postfix(false)
{
  if (!this->parseInput(s) || !checkTokenList(this))
    {
      this->valid = false;
      std::cout << "Expression '" << s << "' is invalid" << std::endl;
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

//Cuts the string s into a singly linked list of Tokens
int	TokenList::parseInput(std::string& s)
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
      else if (s[i] == ' ')
	++i;
      else
	return 0;
    }
  return 1;
}

//Add a token t at the end of the list
void	TokenList::addToken(Token *t)
{
  if (tail)
    tail->addToken(t);
  else
    head = t;
  tail = t;
}

//Add a token at the end of the list from a string s
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

