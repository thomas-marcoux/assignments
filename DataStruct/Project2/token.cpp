#include <iostream>
#include "token.h"

Token::Token(std::string& s)
{
  this->item = std::string(s);
  this->next = NULL;
}

Token::~Token() {}

std::string	Token::getItem() const
{
  return item;
}

Token*	Token::getNext() const
{
  return next;
}

void	Token::addToken(Token* t)
{
  this->next = t;
}

void	Token::print() const
{
  std::cout << item << std::endl;
}
