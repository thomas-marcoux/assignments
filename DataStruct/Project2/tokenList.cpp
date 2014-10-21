#include <iostream>
#include <sstream>
#include "tokenList.h"

TokenList::TokenList(std::string& s)
{
  head = NULL;
  tail = NULL;
  this->parseInput(s);
}

void	TokenList::parseInput(std::string& s)
{
  std::istringstream	ss(s);
  std::string	buff;

  while (!ss.eof())
    {
      getline(ss, buff, DELIMITER);
      this->addToken(buff);
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

void	TokenList::addToken(std::string &s)
{
  Token	*n = new Token(s);
  this->addToken(n);    
}

void	TokenList::addToken(Token *t)
{
  if (tail)
    tail->addToken(t);
  else
    head = t;
  tail = t;
}

void	TokenList::print() const
{
  for (Token *it = head; it; it = it->getNext())
    it->print();
}
