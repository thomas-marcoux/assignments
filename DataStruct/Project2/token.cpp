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
#include "token.h"

Token::Token(std::string const& s)
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
  std::cout << item << " ";
}

bool	Token::operator==(std::string s)
{
  return (this->item == s);
}
