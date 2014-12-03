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
