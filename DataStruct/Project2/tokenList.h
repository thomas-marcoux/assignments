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

#ifndef TOKENLIST_H
#define TOKENLIST_H

#include "token.h"


enum	State {
  STATE0,
  STATE1,
  STATE2,
  STATE3
};

class	TokenList
{
 public:
  TokenList();
  TokenList(std::string&);
  ~TokenList();
  void	parseInput(std::string&);
  bool	checkTokenList() const;
  void	addToken(Token*);
  void	addToken(const char*);
  void	addToken(std::string);
  void	pushFront(std::string);
  void	print() const;
  Token*	getHead() const;
  TokenList*	toPostfix();
  int	evalPostfix();
 private:
  Token*	head;
  Token*	tail;
  bool		valid;
};

#endif
