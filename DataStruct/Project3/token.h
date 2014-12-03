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

#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class	Token
{
 public:
  Token(std::string const&);
  ~Token();
  void	addToken(Token*);
  Token*	getNext() const;
  std::string	getItem() const;
  void	print() const;
  bool	operator==(std::string);
 private:
  std::string	item;
  Token*	next;
};

#endif
