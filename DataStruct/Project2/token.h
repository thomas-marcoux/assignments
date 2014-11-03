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
