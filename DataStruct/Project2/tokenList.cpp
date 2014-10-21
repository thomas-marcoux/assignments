#include <iostream>
#include "tokenList.h"

TokenList::TokenList(std::string& s)
{
  head = NULL;
  tail = NULL;
  this->parseInput(s);
}

void	TokenList::parseInput(std::string& s)
{
  int	length = s.size();
  int	pos = 0;
  std::string	tk;

  for (int i = 0; pos != std::string::npos && i < length; i += pos)
    {
      pos = s.find(DELIMITER, i, length);
      if (pos != std::string::npos)
	tk = s.substr(i, length);
      else
	tk = s.substr(i, pos);
      this->addToken(tk);
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
